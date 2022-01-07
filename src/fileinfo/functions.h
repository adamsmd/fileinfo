#ifndef FILEINFO_FUNCTIONS_H
#define FILEINFO_FUNCTIONS_H

#include <fileinfo/types.h>

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool fileinfo_get_stat(const char *pathname, bool follow_symlink, fileinfo *output);

#ifdef __cplusplus
}
#endif

#endif /* FILEINFO_FUNCTIONS_H */
