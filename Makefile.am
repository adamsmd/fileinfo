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
  fileinfo-fields-dynamic \
  fileinfo-fields-static \
  fileinfo-file-static \
  fileinfo-file-dynamic \
  fileinfo-cpp

fileinfo_fields_dynamic_SOURCES = tests/fileinfo-fields-dynamic.c
fileinfo_fields_dynamic_LDADD = libfileinfo.a

fileinfo_fields_static_SOURCES = tests/fileinfo-fields-static.c
fileinfo_fields_static_LDADD = libfileinfo.a

fileinfo_file_dynamic_SOURCES = tests/fileinfo-file-dynamic.c
fileinfo_file_dynamic_LDADD = libfileinfo.a

fileinfo_file_static_SOURCES = tests/fileinfo-file-static.c
fileinfo_file_static_LDADD = libfileinfo.a

fileinfo_cpp_SOURCES = tests/fileinfo-cpp.cpp
fileinfo_cpp_LDADD = libfileinfo.a
