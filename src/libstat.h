#ifndef LIBSTAT_H
#define LIBSTAT_H
// TODO: automake header conditionals

#include <stddef.h>

#define FIELD_NAME_SIZE 64

struct field {
  ptrdiff_t const offset;
  size_t const size;
  char const name[FIELD_NAME_SIZE]; // not `char *` so fields ends up in .rodata
};

extern struct field const fields[];

#endif // LIBSTAT_H
