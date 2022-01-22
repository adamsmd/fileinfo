#include <fileinfo/dynamic.h>
#include <fileinfo/functions.h>

#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int arg;

  char *stat = (char*)malloc(fileinfo_size);
  if (stat == NULL) {
    printf("error: malloc failed: %s\n", strerror(errno));
    return 1;
  }

  for (arg = 1; arg < argc; arg++) {
    size_t field_index;
    memset(stat, 0, fileinfo_size);

    errno = 0;
    bool result = fileinfo_get_stat(argv[arg], false, (fileinfo*)stat);
    printf("errno %d, %s\n", errno, strerror(errno));
    printf("file: %s\n", argv[arg]);
    printf("status: %d\n", result);

    for (field_index = 0; field_index < fileinfo_fields_length; field_index++) {
      fileinfo_field field = fileinfo_fields[field_index];
      uintmax_t value;
      void *base = stat + field.offset;
      switch (8 * field.size) {
        case   8: value = *( uint8_t*)base; break;
        case  16: value = *(uint16_t*)base; break;
        case  32: value = *(uint32_t*)base; break;
        case  64: value = *(uint64_t*)base; break;
        /* case 128: value = *(uint128_t*)base; break; */
        default:
          printf("error: unknown field size: %"PRIuMAX"\n", (uintmax_t)field.size);
          exit(1);
          break;
      }
      printf("%-12s = %12"PRIuMAX"\n", field.name, value);
    }
  }

  return 0;
}
