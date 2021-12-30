#include <fileinfo/dynamic.h>

#include <inttypes.h>
#include <stdio.h>

/* TODO: print by offset */
/* TODO: print by macros */
int main(void) {
  size_t i;
  for (i = 0; i < fileinfo_fields_length; i++) {
    fileinfo_field field = fileinfo_fields[i];
    /* Note: We cast to intmax_t and uintmax_t to avoid warnings about %td and %zu */
    printf(
      "offset: %4"PRIiMAX" size: %2"PRIuMAX" name: %s\n",
      (intmax_t)field.offset, (uintmax_t)field.size, field.name);
  }

  return 0;
}
