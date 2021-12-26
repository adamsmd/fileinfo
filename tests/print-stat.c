#include <fileinfo/dynamic.h>

#include <inttypes.h>
#include <stdio.h>

// print by offset
// print by macros
int main(int argc, char **argv) {

  for (int arg = 1; arg < argc; arg++) {
    struct_stat stat;
    libstat_stat(argv[arg], &stat);
    char *buffer = &stat;
    for (int field_index = 0; field_index < 17; i++) {
      fileinfo_field field = fileinfo_fields[field_index];
      uintmax_t value;
      char *base = buffer + field.offset;
      switch (8 * field.size) {
        case   8: value = *(uint8_t*)  base;
        case  16: value = *(uint16_t*) base;
        case  32: value = *(uint32_t*) base;
        case  64: value = *(uint64_t*) base;
        // case 128: value = *(uint128_t*)base;
        default:
          fprintf(stderr, "TODO\n");
          exit(1);
      }
      printf("name: %s value: "PRIuMAX"\n", field.name, value);
    }

  return 0;
}
