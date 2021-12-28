AM_CPPFLAGS=@AM_CPPFLAGS@
AM_CFLAGS=@AM_CFLAGS@
AM_CXXFLAGS=@AM_CXXFLAGS@
AM_LDFLAGS=@AM_LDFLAGS@

# AM_CFLAGS = -std=c11
# AM_LDFLAGS = -std=c11
lib_LIBRARIES = libfileinfo.a
# TODO: test to check that .data is empty

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
