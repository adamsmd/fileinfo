AM_CPPFLAGS=@AM_CPPFLAGS@
AM_CFLAGS=@AM_CFLAGS@
AM_CXXFLAGS=@AM_CXXFLAGS@
AM_LDFLAGS=@AM_LDFLAGS@

# AM_CFLAGS = -std=c11
# AM_LDFLAGS = -std=c11
# TODO: test to check that .data is empty
lib_LIBRARIES = libfileinfo.a
libfileinfo_a_SOURCES = src/fileinfo.c

# TODO: include_HEADERS
# TODO: dist files
# TODO: -O3
# TESTS=...
# check_PROGRAMS=...
# TESTS = $(check_PROGRAMS)
check_PROGRAMS = \
  print-fields-dynamic \
  print-fields-static \
  print-stat-static \
  print-stat-dynamic

print_fields_dynamic_SOURCES = tests/print-fields-dynamic.c
print_fields_dynamic_LDADD = libfileinfo.a

print_fields_static_SOURCES = tests/print-fields-static.c
print_fields_static_LDADD = libfileinfo.a

print_stat_dynamic_SOURCES = tests/print-stat-dynamic.c
print_stat_dynamic_LDADD = libfileinfo.a

print_stat_static_SOURCES = tests/print-stat-static.c
print_stat_static_LDADD = libfileinfo.a
