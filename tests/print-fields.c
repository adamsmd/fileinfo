#include <libstat.h>
#include <stdio.h>

int main() {

  for (int i = 0; i < 17; i++) {
    printf("offset: %4td size: %2zd name: %s\n", fields[i].offset, fields[i].size, fields[i].name);
  }

  return 0;
}
