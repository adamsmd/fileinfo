#include <liststat.h>

#include <inttypes.h>
#include <stdio.h>

// print by offset
// print by macros
int main(int argc, char **argc) {

  for (int arg = 1; arg < argc; arg++) {
    struct_stat stat;
    libstat_stat(argv[i], &stat);
    char *buffer = &stat;
    for (int i = 0; i < 17; i++) {
      uintmax_t value;
      char *base = buffer + fields[i].offset;
      switch (8 * fields[i].size) {
        case   8: value = *(uint8_t*)  base;
        case  16: value = *(uint16_t*) base;
        case  32: value = *(uint32_t*) base;
        case  64: value = *(uint64_t*) base;
        // case 128: value = *(uint128_t*)base;
        default:
          fprintf(stderr, "TODO\n");
          exit(1);
      }
      printf("name: %s value: "PRIuMAX"\n", fields[i].name, value);
    }

  return 0;
}
