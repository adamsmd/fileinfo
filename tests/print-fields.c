#include <fileinfo/dynamic.h>
#include <stdio.h>

int main(void) {
  size_t i;
  for (i = 0; i < fileinfo_fields_length; i++) {
    fileinfo_field field = fileinfo_fields[i];
    printf("offset: %4td size: %2zu name: %s\n", field.offset, field.size, field.name);
  }

  return 0;
}
