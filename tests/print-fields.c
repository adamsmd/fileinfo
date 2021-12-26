#include <fileinfo/dynamic.h>
#include <stdio.h>

int main() {

  for (size_t i = 0; i < fileinfo_fields_length; i++) {
    fileinfo_field field = fileinfo_fields[i];
    printf("offset: %4td size: %2zd name: %s\n", field.offset, field.size, field.name);
  }

  return 0;
}
