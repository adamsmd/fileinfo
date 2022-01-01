#include <fileinfo/dynamic.h>

#include <inttypes.h>
#include <stdio.h>

int main(void) {
  size_t i;
  for (i = 0; i < fileinfo_fields_length; i++) {
    fileinfo_field field = fileinfo_fields[i];
    /* Note: We cast to intmax_t and uintmax_t to avoid warnings about %td and %zu */
    printf(
      "offset: %4"PRIdMAX" size: %2"PRIuMAX" name: %s\n",
      (intmax_t)field.offset, (uintmax_t)field.size, field.name);
  }

  return fileinfo_fields_length != 0;
}
