AM_CFLAGS = -std=c11 -pedantic -Wall -Wextra
lib_LIBRARIES = libfileinfo.a
libfileinfo_a_SOURCES = src/fileinfo.c src/fileinfo/static.h src/fileinfo/dynamic.h
# TODO: include_HEADERS
# TODO: dist files
# TODO: -O3
# TESTS=...
# check_PROGRAMS=...
# TESTS = $(check_PROGRAMS)
check_PROGRAMS = print-fields

print_fields_SOURCES = tests/print-fields.c src/fileinfo/dynamic.h
print_fields_LDADD = libfileinfo.a
