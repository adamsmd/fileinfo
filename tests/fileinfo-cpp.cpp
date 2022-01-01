#include <fileinfo/dynamic.h>
#include <fileinfo/functions.h>
#include <fileinfo/static.h>

// TODO: conditional make based on whether have c++ compiler
int main(void) {
  fileinfo_get_stat(0, false, 0); // Just test whether we can link against it
  return 0;
}
