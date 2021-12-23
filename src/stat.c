#include "config.h"

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <linux/stat.h>

static const int buffer_size = sizeof(struct stat); // TODO: or statx

int get_stat(const char *pathname, bool follow_symlink, void *buffer) {

  #if HAVE_STATX
    struct statx *statxbuf = buffer;
    // statx(STATX_ALL, buffer);

  #elif HAVE_STAT
    struct stat *statbuf = buffer;
    int stat(pathname, statbuf);

  #endif

  return 0;
}

void set_stat() {

}

// TODO: to_json
