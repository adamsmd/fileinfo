#ifndef FILEINFO_DYNAMIC_H
#define FILEINFO_DYNAMIC_H

#include <fileinfo/types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern size_t const fileinfo_size;

extern fileinfo_field const fileinfo_fields[];
extern size_t const fileinfo_fields_length;

#ifdef __cplusplus
}
#endif

#endif /* FILEINFO_DYNAMIC_H */
