#include "fileinfo/functions.h"
#include "fileinfo/static.h"

#include "config.h"

#if HAVE_STDBOOL_H
#include <stdbool.h>
#endif

#if HAVE_STDDEF_H
#include <stddef.h>
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#if HAVE_SYS_TYPES_H
#include <sys/stat.h>
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#if HAVE_LINUX_FCNTL_H
#include <linux/fcntl.h> /* Definition of AT_* constants */
#endif

#if HAVE_LINUX_STAT_H
#include <linux/stat.h>

#if HAVE_STATX
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

const int buffer_size = sizeof(fileinfo_stat);

#define sizeof_field(field) (sizeof(((fileinfo_stat*)NULL)->field))

#define INT(field,name) { offsetof(fileinfo_stat,field), sizeof_field(field), #name },
#define DEV(field,name,major,minor) INT(field,name)
#define TIME_SEC(field,name) INT(field,name)
#define TIME_NSEC(field,name) INT(field,name)
fileinfo_field const fileinfo_fields[] = { /* TODO: put in ro memory */
  STAT_FIELDS(INT,DEV,TIME_SEC,TIME_NSEC)
};
size_t const fileinfo_fields_length = STAT_FIELDS_COUNT;

/* TODO: create struct of right shape */
/* TODO: define field accessors */

int fileinfo_get_stat(const char *pathname, bool follow_symlink, fileinfo *output) {

  /* TODO: implement get_stat */
  #if USE_STATX
    /* TODO: dirfd support */
    int flags = follow_symlink ? AT_SYMLINK_FOLLOW : AT_SYMLINK_NOFOLLOW;
    if (0 == statx(AT_FDCWD, pathname, flags, STATX_ALL, &output->stat)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
    /* TODO: if use_statx make_dev(base) */
  #elif defined(USE_FSTATAT64) || defined(USE_FSTATAT)
    if (0 ==
      #if USE_FSTATAT64
        fstatat64
      #elif USE_FSTATAT
        fstatat
      #else
        #error "TODO"
      #endif
      (AT_FDCWD, pathconf, &output->stat, follow_symlink ? AT_SYMLINK_FOLLOW : AT_SYMLINK_NOFOLLOW)) {
      return true;
    } else {
      return false;
      /* TODO: error based on errno */
    }
  #elif defined(USE_STAT64) || defined(USE_STAT)
    if (0 ==
      follow_symlink ?
        #if USE_STAT64
          stat64
        #elif USE_STAT
          stat
        #else
          #error "TODO"
        #endif
        (pathname, &output->stat) :
        #if USE_STAT64
          lstat64
        #elif USE_STAT
          lstat
        #else
          #error "TODO"
        #endif
        (pathname, &output->stat)) {
      return true;
    } else {
      return false;
    }
  #else
    #error "unimplemented"
  #endif

  return 0;
}
