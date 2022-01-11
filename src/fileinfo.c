#include "fileinfo/functions.h"
#include "fileinfo/static.h"

#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#include "headers.h"

/* We cannot include fnctl.h and linux/fnctl.h at the same time */
#ifndef HAVE_FCNTL_H
  #ifdef HAVE_LINUX_FCNTL_H
    #include <linux/fcntl.h>
  #endif
#endif

#ifdef HAVE_STRUCT_STATX
  #ifdef HAVE_STATX
    /* Taken from `man statx` as the headers don't have this function.*/
    extern int statx(
      int dirfd, const char *pathname, int flags, unsigned int mask, struct statx *statxbuf);
  #else
    #include <sys/syscall.h>
    /* Older glibc didn't have a statx function, so we use syscall */
    static int statx(
        int dirfd, const char *pathname, int flags, unsigned int mask, struct statx *statxbuf) {
      return (int)syscall(SYS_statx, dirfd, pathname, flags, mask, statxbuf);
    }
  #endif
#endif

size_t const fileinfo_size = sizeof(fileinfo);

#define INT(field,name) { \
  offsetof(fileinfo,stat.field), \
  sizeof(((fileinfo*)NULL)->stat.field), \
  #name },
#define DEV(field,name,major,minor) INT(field,name)
#define TIME_SEC(field,name) INT(field,name)
#define TIME_NSEC(field,name) INT(field,name)
fileinfo_field const fileinfo_fields[] = { /* TODO: put in ro memory */
  FILEINFO_STAT_FIELDS(INT,DEV,TIME_SEC,TIME_NSEC)
};
size_t const fileinfo_fields_length = FILEINFO_FIELDS_LENGTH;

/* TODO: define field accessors */

/**
 * @brief Get info about `pathname`
 *
 * @param[in] pathname The filename to get information about
 * @param[in] follow_symlink Whether to follow symlinks
 * @param[out] output A pointer to the `fileinfo` struct into which to write the information about `pathname`.
 * @return bool True if the data was successfully retrieved.
 */
bool fileinfo_get_stat(const char *pathname, bool follow_symlink, fileinfo *output) {
  #if defined(HAVE_STRUCT_STATX)
    /* TODO: dirfd support */
    int flags = follow_symlink ? AT_SYMLINK_FOLLOW : AT_SYMLINK_NOFOLLOW;
    if (0 == statx(AT_FDCWD, pathname, flags, STATX_ALL, &output->stat)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
    /* TODO: if use_statx make_dev(base) */
  #elif defined(HAVE_FSTATAT64) || defined(HAVE_FSTATAT)
    #if defined(HAVE_FSTATAT64)
      #define STAT fstatat64
    #elif defined(HAVE_FSTATAT)
      #define STAT fstatat
    #else
      #error "internal error: impossible case"
    #endif
    if (0 == STAT(AT_FDCWD, pathname, &output->stat, follow_symlink ? AT_SYMLINK_FOLLOW : AT_SYMLINK_NOFOLLOW)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
    /* TODO: _stat32? */
  #elif defined(HAVE_STAT64) || defined(HAVE__STAT64) || defined(HAVE_STAT)
    #if defined(HAVE_STAT64)
      #define STAT stat64
    #elif defined(HAVE__STAT64)
      #define STAT _stat64
    #elif defined(HAVE_STAT)
      #define STAT stat
    #else
      #error "internal error: impossible case"
    #endif

    #if defined(HAVE_LSTAT64)
      #define LSTAT lstat64
    #elif defined(HAVE_LSTAT)
      #define LSTAT lstat
    #else
      #define LSTAT STAT
    #endif

    if (follow_symlink ? STAT(pathname, &output->stat) : LSTAT(pathname, &output->stat)) {
      return true;
    } else {
      return false;
    }
  #else
    #error "unimplemented case for fileinfo_get_stat"
  #endif
}

/* TODO: intmax_t fileinfo_get_field (size_t index, fileinfo const *) */
