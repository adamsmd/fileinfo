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

struct field {
  char const * const name;
  ptrdiff_t const offset;
  size_t const size;
};

#define sizeof_field(field) (sizeof(((struct_stat*)NULL)->field))

#define INT(field,name) { #name, offsetof(struct_stat,field), sizeof_field(field) },
#define DEV(field,name,major,minor) INT(field,name)
#define TIME_SEC(field,name) INT(field,name)
#define TIME_NSEC(field,name) INT(field,name)
struct field const fields[] = {
  STAT_FIELDS(INT,DEV,TIME_SEC,TIME_NSEC)
};

// TODO: create struct of right shape
// TODO: define field accessors

void print_fields() {

}

int get_stat(const char *pathname, bool follow_symlink, void *buffer) {

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

void set_stat() {
  // TODO: set_stat
}

// TODO: to_json
