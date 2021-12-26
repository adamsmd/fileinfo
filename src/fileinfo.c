#include "fileinfo/static.h"
#include "fileinfo/dynamic.h"

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
#include <fcntl.h>           /* Definition of AT_* constants */
#endif

#if HAVE_LINUX_STAT_H
#include <linux/stat.h>
#endif

#if USE_STATX
typedef struct statx struct_stat;
#elif USE_STAT
typedef struct stat struct_stat;
#else
#error "unimplemented"
#endif

const int buffer_size = sizeof(struct_stat);

// TODO: test to check that .data is empty

#define sizeof_field(field) (sizeof(((struct_stat*)NULL)->field))

#define INT(field,name) { offsetof(struct_stat,field), sizeof_field(field), #name },
#define DEV(field,name,major,minor) INT(field,name)
#define TIME_SEC(field,name) INT(field,name)
#define TIME_NSEC(field,name) INT(field,name)
fileinfo_field const fileinfo_fields[] = { // TODO: put in ro memory
  STAT_FIELDS(INT,DEV,TIME_SEC,TIME_NSEC)
};
size_t const fileinfo_fields_length = STAT_FIELDS_COUNT;

// TODO: create struct of right shape
// TODO: define field accessors

int fileinfo_stat(const char *pathname, bool follow_symlink, void *buffer) {

  struct_stat *statxbuf = buffer;
  // TODO: implement get_stat
  #if USE_STATX
    // statx(STATX_ALL, buffer);
    // TODO: if use_statx make_dev(base)
  #elif USE_STAT
    // int stat(pathname, statbuf);
  #else
  #error "unimplemented"
  #endif

  return 0;
}


// void set_stat() {
//   // TODO: set_stat
// }

// TODO: to_json
