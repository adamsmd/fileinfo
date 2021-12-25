AM_CFLAGS = -std=c11 -pedantic -Wall -Wextra
lib_LIBRARIES = libstat.a
libstat_a_SOURCES = src/stat.c src/libstat.h
# TODO: include_HEADERS
# TODO: dist files
# TODO: -O3
# TESTS=...
# check_PROGRAMS=...
# TESTS = $(check_PROGRAMS)
check_PROGRAMS = print-fields

print_fields_SOURCES = tests/print-fields.c src/libstat.h
print_fields_LDADD = libstat.a
