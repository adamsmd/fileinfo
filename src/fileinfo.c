#include "fileinfo/functions.h"
#include "fileinfo/static.h"
#include "fileinfo/dynamic.h"

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

/* Taken from `man stat64` and `man lstat64` as the headers don't have these functions.*/
#if defined(HAVE_STRUCT_STAT64)
  #define STRUCT_STAT64 struct stat64
#else
  #define STRUCT_STAT64 struct stat
#endif
extern int stat64(const char *pathname, STRUCT_STAT64 *statbuf);
extern int lstat64(const char *pathname, STRUCT_STAT64 *statbuf);

/******************************************************************************/

static inline int fileinfo_get_stat_helper(const char *pathname, bool follow_symlink, struct stat *output) {
  #define CALL_FSTATAT(func) return func(AT_FDCWD, pathname, output, follow_symlink ? 0 : AT_SYMLINK_NOFOLLOW)
  #define CALL_STAT(func, lfunc) return follow_symlink ? func(pathname, (STRUCT_STAT64*)output) : lfunc(pathname, (STRUCT_STAT64*)output)

  /* TODO: _stat32? */
  #if defined(HAVE_FSTATAT64)
    CALL_FSTATAT(fstatat64);
  #elif defined(HAVE_STAT64)
    #if !defined(HAVE_LSTAT64)
      #error "have stat64 but not lstat64"
    #endif
    CALL_STAT(stat64, lstat64);
  #elif defined(HAVE__STAT64)
    #if !defined(HAVE__LSTAT64)
      #error "have _stat64 but not _lstat64"
    #endif
    CALL_STAT(_stat64, _lstat64);
  #elif defined(HAVE_FSTATAT)
    CALL_FSTATAT(fstatat);
  #elif defined(HAVE_STAT)
    #if !defined(HAVE__STAT)
      #error "have stat but not lstat"
    #endif
    CALL_STAT(stat, lstat);
  #else
    #error "unimplemented case for fileinfo_get_stat_helper"
  #endif
}

/******************************************************************************/

#ifdef HAVE_STRUCT_STATX
  /* Some glibc statx implementations do not support AT_SYMLINK_NOFOLLOW so we implement statx ourselves */
  static inline struct statx_timestamp statx_timestamp_from_timespec(struct timespec tv) {
    struct statx_timestamp ret;
    ret.tv_sec = (__s64)tv.tv_sec;
    ret.tv_nsec = (__u32)tv.tv_nsec;
    return ret;
  }

  static inline long statx_syscall(const char *pathname, bool follow_symlink, struct statx *statxbuf) {
    int flags = follow_symlink ? 0 : AT_SYMLINK_NOFOLLOW;
    long ret = syscall(SYS_statx, AT_FDCWD, pathname, flags, STATX_ALL, statxbuf);

    if (ret == 0 || errno != ENOSYS) {
      return (int)ret;
    } else {
      struct stat output;

      ret = fileinfo_get_stat_helper(pathname, follow_symlink, &output);

      if (ret == 0) {
        statxbuf->stx_mask = (__u32)STATX_BASIC_STATS;
        statxbuf->stx_blksize = (__u32)output.st_blksize;
        /* stx_attributes */
        statxbuf->stx_nlink = (__u32)output.st_nlink;
        statxbuf->stx_uid = (__u32)output.st_uid;
        statxbuf->stx_gid = (__u32)output.st_gid;
        statxbuf->stx_mode = (__u16)output.st_mode;
        statxbuf->stx_ino = (__u64)output.st_ino;
        statxbuf->stx_size = (__u64)output.st_size;
        statxbuf->stx_blocks = (__u64)output.st_blocks;
        statxbuf->stx_attributes_mask = (__u64)0;

        statxbuf->stx_atime = statx_timestamp_from_timespec(output.st_atim);
        /* stx_btime */
        statxbuf->stx_ctime = statx_timestamp_from_timespec(output.st_ctim);
        statxbuf->stx_mtime = statx_timestamp_from_timespec(output.st_mtim);

        statxbuf->stx_rdev_major = (__u32)major(output.st_rdev);
        statxbuf->stx_rdev_minor = (__u32)minor(output.st_rdev);
        statxbuf->stx_dev_major = (__u32)major(output.st_dev);
        statxbuf->stx_dev_minor = (__u32)minor(output.st_dev);
        /* stx_mnt_id */
      }

      return (int)ret;
    }
  }
#endif

/******************************************************************************/

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

/******************************************************************************/

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
    if (0 == statx_syscall(pathname, follow_symlink, &output->stat)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
    /* TODO: if use_statx make_dev(base) */
  #else
    if (0 == fileinfo_get_stat_helper(pathname, follow_symlink, &output->stat)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
  #endif
}

/* TODO: intmax_t fileinfo_get_field (size_t index, fileinfo const *) */
