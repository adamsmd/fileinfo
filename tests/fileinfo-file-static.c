#include <fileinfo/static.h>
#include <fileinfo/functions.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int arg;
  for (arg = 1; arg < argc; arg++) {
    fileinfo fi;
    char *stat = (char*)&fi;
    size_t field_index;

    fileinfo_get_stat(argv[arg], false, &fi);

    for (field_index = 0; field_index < fileinfo_fields_length_static; field_index++) {
      fileinfo_field field = fileinfo_fields_static[field_index];
      uintmax_t value;
      void *base = stat + field.offset;
      switch (8 * field.size) {
        case   8: value = *(uint8_t*)  base; break;
        case  16: value = *(uint16_t*) base; break;
        case  32: value = *(uint32_t*) base; break;
        case  64: value = *(uint64_t*) base; break;
        /* case 128: value = *(uint128_t*)base; */
        default:
          /* fprintf(stderr, "error: unknown field size: %"PRIuMAX"\n", (uintmax_t)field.size); */
          exit(1);
          break;
      }
      printf("%-12s = %12"PRIuMAX"\n", field.name, value);
    }
  }

  return 0;
}
