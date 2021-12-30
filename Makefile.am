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
check_PROGRAMS = \
  print-fields-dynamic \
  print-stat-dynamic

print_fields_dynamic_SOURCES = tests/print-fields-dynamic.c src/fileinfo/dynamic.h
print_fields_dynamic_LDADD = libfileinfo.a

print_stat_dynamic_SOURCES = tests/print-stat-dynamic.c src/fileinfo/dynamic.h
print_stat_dynamic_LDADD = libfileinfo.a
