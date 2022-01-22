#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([fileinfo], [0.1.0], [https://github.com/adamsmd/fileinfo])
AC_CONFIG_SRCDIR([src/fileinfo.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])

################
# Standard sections

#### Checks for programs.
AM_PROG_AR
AC_SUBST([ARFLAGS], [cr]) # Prevent "ar: `u' modifier ignored since `D' is the default (see `U')"
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB
# AC_PROG_CXX # TODO: optional

#### Checks for libraries.

#### Checks for header files.
AS_VAR_SET([ac_headers_h], ["src/headers.h"])
AS_ECHO_N() >"$ac_headers_h"
AC_DEFUN([CHECK_INCLUDE_HEADERS], [
  AC_CHECK_HEADERS([$1])
  # This implementation is similar to AX_AUTO_INCLUDE_HEADERS but does not use
  # the depricated AC_FOREACH and I couldn't get AX_AUTO_INCLUDE_HEADERS to work
  # anyway
  m4_foreach_w([check_include_header], [$1], [
    m4_pushdef([AX_IfDef], AS_TR_CPP(HAVE_[]check_include_header))dnl
    cat >>"$ac_headers_h" <<EOT
[#]ifdef AX_IfDef
[#] include <check_include_header>
[#]endif

EOT
])
]) # AUTO_HEADERS

AC_HEADER_ASSERT
AC_HEADER_MAJOR
AC_HEADER_STDBOOL

CHECK_INCLUDE_HEADERS([ \
  assert.h \
  errno.h \
  fcntl.h \
  linux/stat.h \
  stdbool.h \
  stddef.h \
  sys/mkdev.h \
  sys/stat.h \
  sys/syscall.h \
  sys/sysmacros.h \
  sys/types.h \
  unistd.h \
])

# This header cannot be included at the same time as fcntl.h
AC_CHECK_HEADERS([linux/fcntl.h])

#### Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_SIZE_T

AC_CHECK_TYPE([struct statx], [], [], [[#include <linux/stat.h>]])
AC_CHECK_TYPES([
  struct _stat64,
  struct stat,
  struct stat64],
  [], [], [[#include <sys/stat.h>]])
AC_CHECK_TYPES([
  ptrdiff_t])

# Setup include headers and typedefs for including stat
AH_TEMPLATE([HAVE_STRUCT_STATX], [Define to 1 if we should use the `stat' function.])
AS_IF(
  [test "x$ac_cv_type_struct_statx" = xyes], [
    AC_DEFINE(HAVE_STRUCT_STATX, 1)
    declare_fileinfo_stat="
      [#include <linux/stat.h>]
      [typedef struct statx fileinfo_stat;]
      "],
  [test "x$ac_cv_type_struct_stat64" = xyes], [
    declare_fileinfo_stat="
      [#include <sys/stat.h>]
      [typedef struct stat64 fileinfo_stat;]
      "],
  [test "x$ac_cv_type_struct__stat64" = xyes], [
    declare_fileinfo_stat="
      [#include <sys/stat.h>]
      [typedef struct _stat64 fileinfo_stat;]
      "],
  [test "x$ac_cv_type_struct_stat" = xyes], [
    declare_fileinfo_stat="
      [#include <sys/stat.h>]
      [typedef struct stat fileinfo_stat;]
      "],
  [AC_MSG_ERROR([cannot find `struct stat` or any similar struct])])
AC_SUBST([DECLARE_FILEINFO_STAT], ["$declare_fileinfo_stat"])
AM_SUBST_NOTMAKE([DECLARE_FILEINFO_STAT])
preamble="
  AC_INCLUDES_DEFAULT
  $declare_fileinfo_stat
  "

#### Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([ \
  _stat64 \
  fstat \
  fstatat \
  lstat \
  stat \
  stat64 \
  statx \
])

#### Checks for system services.

#### Checks from Autoconf Archive <https://www.gnu.org/software/autoconf-archive/>.

# TODO: rpm and deb packaging?

# tools:
# ax_check_sign - check if signed
# ax_check_func_in - check for function in header
# ax_require_one_func
# ax_libtoolize_cflags - prefix flags with -Xcompiler
# ax_append_compile_flags - try flags
#   ax_check_compile_flag
#   ax_check_preproc_flag

# ax_c99_inline - test if force inline works
#   ax_forceinline
# ax_c___attribute__ - test if __attribute__ is supported
#   ax_gcc_func_attribute
#   ax_gcc_var_attribute

AX_CREATE_PKGCONFIG_INFO # generate <package>.pc.in and <package>.pc # TODO: unknown version numbers?
AX_VALGRIND_CHECK # make check-valgrind # TODO: test
AX_CODE_COVERAGE # make check-code-coverage # TODO: test
# TODO: other static analysis

## Warnings
AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

AX_CFLAGS_WARN_ALL([AM_CFLAGS])
AX_CFLAGS_NO_WRITABLE_STRINGS([AM_CFLAGS])
m4_define([WARN_CXXFLAGS], [AM_CXXFLAGS]) # make AX_COMPILER_FLAGS use AM_CXXFLAGS
AX_COMPILER_FLAGS([AM_CFLAGS], [AM_LDFLAGS], [yes])

AX_APPEND_COMPILE_FLAGS([-fanalyzer], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wanalyzer-too-complex], [AM_CFLAGS])

AX_APPEND_COMPILE_FLAGS([-pedantic], [AM_CFLAGS])

# -pedantic-errors

# -Wctor-dtor-privacy
# -Weffc++
# -Wnoexcept
# -Wold-style-cast
# -Wsign-promo
# -Wstrict-null-sentinel

#### AX_APPEND_COMPILE_FLAGS([-fsyntax-only], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-fmax-errors=n], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpedantic], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-pedantic-errors], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-w], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wall], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Weverything], [AM_CFLAGS]) # Used by llvm
## AX_APPEND_COMPILE_FLAGS([-Wabi], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wabi=n], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Waddress], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-address-of-packed-member], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Waggregate-return], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Walloc-size-larger-than=1024], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Walloc-zero], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Walloca], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Walloca-larger-than=1024], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wno-aggressive-loop-optimizations], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Warith-conversion], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Warray-bounds], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Warray-bounds=2], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-attributes], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wattribute-alias=2], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-attribute-alias], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-attribute-warning], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wbool-compare], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wbool-operation], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wno-builtin-declaration-mismatch], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-builtin-macro-redefined], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc90-c99-compat], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc99-c11-compat], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc11-c2x-compat], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc++-compat], [AM_CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc++11-compat], [AM_CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc++14-compat], [AM_CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc++17-compat], [AM_CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wc++20-compat], [AM_CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-align], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-align=strict], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-function-type], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-qual], [AM_CFLAGS]) ####
AX_APPEND_COMPILE_FLAGS([-Wchar-subscripts], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wclobbered], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcomment], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wconversion], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-coverage-mismatch], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-cpp], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wdangling-else], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wdate-time], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-deprecated], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-deprecated-declarations], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-designated-init], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wdisabled-optimization], [AM_CFLAGS]) ####
#### AX_APPEND_COMPILE_FLAGS([-Wno-discarded-array-qualifiers], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-discarded-qualifiers], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-div-by-zero], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wdouble-promotion], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wduplicated-branches], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wduplicated-cond], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wempty-body], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-endif-labels], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wenum-compare], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wenum-conversion], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Werror], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Werror=*], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wexpansion-to-defined], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wfatal-errors], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wfloat-conversion], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wfloat-equal], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat=2], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-format-contains-nul], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-format-extra-args], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-nonliteral], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-overflow=2], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-security], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-signedness], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-truncation=2], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat-y2k], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wframe-address], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wframe-larger-than=1024], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-free-nonheap-object], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-if-not-aligned], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-ignored-attributes], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wignored-qualifiers], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-incompatible-pointer-types], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wimplicit], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wimplicit-fallthrough], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wimplicit-fallthrough=5], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-implicit-function-declaration], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-implicit-int], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Winit-self], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Winline], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-int-conversion], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wint-in-bool-context], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-int-to-pointer-cast], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-invalid-memory-model], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Winvalid-pch], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wjump-misses-init], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wlarger-than=4096], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wlogical-not-parentheses], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wlogical-op], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wlong-long], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-lto-type-mismatch], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmain], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmaybe-uninitialized], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmemset-elt-size], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmemset-transposed-args], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmisleading-indentation], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-attributes], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-braces], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-field-initializers], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-format-attribute], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-include-dirs], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-noreturn], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-missing-profile], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-multichar], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmultistatement-macros], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wnonnull], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wnonnull-compare], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wnormalized=nfkc], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wnull-dereference], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-odr], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wopenmp-simd], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-overflow], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Woverlength-strings], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-override-init-side-effects], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpacked], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-packed-bitfield-compat], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpacked-not-aligned], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpadded], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wparentheses], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-pedantic-ms-format], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpointer-arith], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-pointer-compare], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-pointer-to-int-cast], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-pragmas], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-prio-ctor-dtor], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wredundant-decls], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wrestrict], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-return-local-addr], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wreturn-type], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-scalar-storage-order], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsequence-point], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wshadow], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wshadow=global], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wshadow=local], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wshadow=compatible-local], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-shadow-ivar], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-shift-count-negative], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-shift-count-overflow], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wshift-negative-value], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-shift-overflow], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wshift-overflow=1], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsign-compare], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsign-conversion], [AM_CFLAGS]) ####
#### AX_APPEND_COMPILE_FLAGS([-Wno-sizeof-array-argument], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsizeof-array-div], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsizeof-pointer-div], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsizeof-pointer-memaccess], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstack-protector], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstack-usage=1024], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstrict-aliasing], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstrict-aliasing=3], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstrict-overflow], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstrict-overflow=5], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wstring-compare], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-stringop-overflow], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-stringop-overread], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-stringop-truncation], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsuggest-attribute=pure], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsuggest-attribute=const], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsuggest-attribute=noreturn], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsuggest-attribute=format], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsuggest-attribute=malloc], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wswitch], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-switch-bool], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wswitch-default], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wswitch-enum], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-switch-outside-range], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-switch-unreachable], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wsync-nand], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wsystem-headers], [AM_CFLAGS]) # Don't warn from system headers
AX_APPEND_COMPILE_FLAGS([-Wtautological-compare], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wtrampolines], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wtrigraphs], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wtsan], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wtype-limits], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wundef], [AM_CFLAGS]) # Allow #if on undefined vars
AX_APPEND_COMPILE_FLAGS([-Wuninitialized], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunknown-pragmas], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunsuffixed-float-constants], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-but-set-parameter], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-but-set-variable], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wunused-const-variable], [AM_CFLAGS])
## AX_APPEND_COMPILE_FLAGS([-Wunused-const-variable=2], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-const-variable=1], [AM_CFLAGS]) # Don't warn about unused from headers
AX_APPEND_COMPILE_FLAGS([-Wunused-function], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-label], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-local-typedefs], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-macros], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-parameter], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-unused-result], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-value], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wunused-variable], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-varargs], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wvariadic-macros], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wvector-operation-performance], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wvla], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wvla-larger-than=1024], [AM_CFLAGS])
#### AX_APPEND_COMPILE_FLAGS([-Wno-vla-larger-than], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wvolatile-register-var], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wwrite-strings], [AM_CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wzero-length-bounds], [AM_CFLAGS])

################
# Populate `stat_fields` with data about the fields available in `struct stat` or `struct statx`

#### Helpers

# Shell variable holding the CPP macro invocations to be added to the CPP macro `STAT_FIELDS()`
stat_fields=
stat_fields_count=0

# CHECK_STAT(MACRO, FIELD, ARGS...)
# --------------------------------------
# If FIELD is a member of `fileinfo_stat`, add `MACRO(FIELD, ARGS...)` to
# `stat_fields`.
AC_DEFUN([CHECK_STAT], [
  AC_CHECK_MEMBER([fileinfo_stat.$2],
    [AS_VAR_ARITH([stat_fields_count], [1 + $stat_fields_count])
      AS_VAR_APPEND([stat_fields], "[ \\]m4_newline([  $1($2, $3)])")],
    [],
    [$preamble])
]) # CHECK_STAT

#### File type and mode

# TODO: stx_mode/st_mode is handled specially
# TODO: human_access (stat.c)
# TODO: file_type (stat.c)

# SIFMT

# S_IFSOCK
# S_IFLNK
# S_IFREG
# S_IFBLK
# S_IFDIR
# S_IFCHR
# S_IFIFO
# S_IFDOOR
# S_IFPORT
# S_IFWHT

# S_ISSOCK
# S_ISLNK
# S_ISREG
# S_ISBLK
# S_ISDIR
# S_ISCHR
# S_ISIFO
# S_ISDOOR
# S_ISPORT
# S_ISWHT


# S_ISUID     04000   set-user-ID bit (see execve(2))
# S_ISGID     02000   set-group-ID bit (see below)
# S_ISVTX     01000   sticky bit (see below)
# S_IRWXU     00700   owner has read, write, and execute permission
# S_IRUSR     00400   owner has read permission
# S_IWUSR     00200   owner has write permission
# S_IXUSR     00100   owner has execute permission
# S_IRWXG     00070   group has read, write, and execute permission
# S_IRGRP     00040   group has read permission
# S_IWGRP     00020   group has write permission
# S_IXGRP     00010   group has execute permission
# S_IRWXO     00007   others (not in group) have read, write, and execute permission
# S_IROTH     00004   others have read permission
# S_IWOTH     00002   others have write permission
# S_IXOTH     00001   others have execute permission

#  stat.S_ENFMT shared with S_ISGID, valid when file does not have SIXGRP set

# https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html
# S_TYPEISMQ (struct stat *s)
# S_TYPEISSEM (struct stat *s)
# S_TYPEISSHM (struct stat *s)


#### Unsigned integer fields

# CHECK_STATX(NAME)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_INT(stx_NAME)
# - F_INT(st_NAME)
AC_DEFUN([CHECK_STATX], [
  CHECK_STAT([F_INT], stx_$1, [$1])
  CHECK_STAT([F_INT], st_$1, [$1])
]) # CHECK_STATX

CHECK_STATX(ino)     # Inode number
CHECK_STATX(nlink)   # Number of hard links
CHECK_STATX(uid)     # User ID of owner
CHECK_STATX(gid)     # Group ID of owner
CHECK_STATX(size)    # Total size, in bytes
CHECK_STATX(blksize) # Block size for filesystem I/O
CHECK_STATX(blocks)  # Number of 512B blocks allocated

CHECK_STATX(gen) # AIX macOS NetBSD OpenBSD
CHECK_STATX(vfs) # AIX
CHECK_STATX(access) # AIX: st_access 	Field is not implemented. All bits are returned as zero.
CHECK_STATX(mnt_id) # Linux 5.8+

# TODO: getpwuid (stat.c)
# TODO: getgruid (stat.c)
# TODO: string for mnt_id

# TODO: out_mount_point (stat.c)

#### Device fields

# CHECK_DEV(NAME)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_DEV(stx_NAME_major, NAME, stx_NAME_major, stx_NAME_minor)
# - F_DEV(stx_NAME, NAME, stx_NAME, stx_NAME)
AC_DEFUN([CHECK_DEV], [
  CHECK_STAT([F_DEV], stx_$1_major, [$1, stx_$1_major, stx_$1_minor])
  CHECK_STAT([F_DEV], st_$1,        [$1, st_$1, st_$1])
]) # CHECK_DEV

CHECK_DEV(dev)  # ID of device containing file
CHECK_DEV(rdev) # Device ID (if special file)

#### Time fields (seconds)

# CHECK_TIME_SEC(PREFIX)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_TIME_SEC(stx_PREFIXtime.tv_sec, PREFIXtime_sec)
# - F_TIME_SEC(st_PREFIXtime, PREFIXtime_sec)
AC_DEFUN([CHECK_TIME_SEC], [
  CHECK_STAT([F_TIME_SEC], stx_$1time.tv_sec, [$1time_sec])
  CHECK_STAT([F_TIME_SEC], st_$1time,         [$1time_sec])
]) # CHECK_TIME_SEC

CHECK_TIME_SEC([a])
CHECK_TIME_SEC([b])
CHECK_TIME_SEC([c])
CHECK_TIME_SEC([m])

# TODO: btime vs birthtime
# stx_btime # linux
# st_birthtim #freebsd netbsd macOS
# <none> # openbsd solaris aix minix

#### Time fields (nanoseconds)

# CHECK_TIME_NSEC(prefix)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_TIME_SEC(stx_PREFIXtime.tv_sec, PREFIXtime_sec)
# - F_TIME_SEC(st_PREFIXtime, PREFIXtime_sec)
AC_DEFUN([CHECK_TIME_NSEC], [
  CHECK_STAT([F_TIME_NSEC], stx_$1time.tv_nsec, [$1time_nsec]) # linux
  CHECK_STAT([F_TIME_NSEC], st_$1tim.tv_nsec, [$1time_nsec]) # minix openbsd linux
  CHECK_STAT([F_TIME_NSEC], st_$1tim.st__tim.tv_nsec, [$1time_nsec]) # unknown
  CHECK_STAT([F_TIME_NSEC], st_$1timespec.tv_nsec, [$1time_nsec]) # macOS
  CHECK_STAT([F_TIME_NSEC], st_$1time_n, [$1time_nsec]) # aix
  CHECK_STAT([F_TIME_NSEC], st_$1timensec, [$1time_nsec]) # netbsd
  # CHECK_STAT([F_TIME_NSEC], st_$1_none, [$1time_nsec]) # solaris
]) # CHECK_TIME_NSEC

CHECK_TIME_NSEC([a])
CHECK_TIME_NSEC([b])
CHECK_TIME_NSEC([c])
CHECK_TIME_NSEC([m])

#### Enumerated constant fields

# TODO: STAT_FIELD(type) # AIX (vnode type, enum)
# TODO: STAT_FIELD(vfstype) # AIX (enum)
# TODO: STAT_FIELD(flag) # AIX (enum)

#### Bit-flag fields

# TODO: STAT_FIELD(flags) # macOS NetBSD OpenBSD FreeBSD (flags)

# stx_attributes; /* Extra file attribute indicators */
# stx_attributes_mask; /* Mask to show what's supported in stx_attributes */
AC_CHECK_DECLS([
  STATX_ATTR_COMPRESSED,
  STATX_ATTR_IMMUTABLE,
  STATX_ATTR_APPEND,
  STATX_ATTR_NODUMP,
  STATX_ATTR_ENCRYPTED,
  STATX_ATTR_VERITY,
  STATX_ATTR_DAX
  ], [], [], [[#include <linux/stat.h>]])

# stat(?).flags https://manpages.debian.org/jessie/freebsd-manpages/chflags.2freebsd.en.html
AC_CHECK_DECLS([
  SF_APPEND,
  SF_ARCHIVED,
  SF_IMMUTABLE,
  SF_NOUNLINK,
  SF_SNAPSHOT,
  UF_APPEND,
  UF_ARCHIVE,
  UF_HIDDEN,
  UF_IMMUTABLE,
  UF_NODUMP,
  UF_NOUNLINK,
  UF_OFFLINE,
  UF_OPAQUE,
  UF_READONLY,
  UF_REPARSE,
  UF_SPARSE,
  UF_SYSTEM
], [], [], [[#inclue <sys/stat.h>]])

# # windows https://docs.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
# FILE_ATTRIBUTE_ARCHIVE
# FILE_ATTRIBUTE_COMPRESSED
# FILE_ATTRIBUTE_DEVICE
# FILE_ATTRIBUTE_DIRECTORY
# FILE_ATTRIBUTE_ENCRYPTED
# FILE_ATTRIBUTE_HIDDEN
# FILE_ATTRIBUTE_INTEGRITY_STREAM
# FILE_ATTRIBUTE_NORMAL
# FILE_ATTRIBUTE_NOT_CONTENT_INDEXED
# FILE_ATTRIBUTE_NO_SCRUB_DATA
# FILE_ATTRIBUTE_OFFLINE
# FILE_ATTRIBUTE_READONLY
# FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS
# FILE_ATTRIBUTE_RECALL_ON_OPEN
# FILE_ATTRIBUTE_REPARSE_POINT
# FILE_ATTRIBUTE_SPARSE_FILE
# FILE_ATTRIBUTE_SYSTEM
# FILE_ATTRIBUTE_TEMPORARY
# FILE_ATTRIBUTE_VIRTUAL

# # windows st_reparse_tag https://docs.microsoft.com/en-us/windows/win32/fileio/reparse-point-tags
# IO_REPARSE_TAG_AF_UNIX
# IO_REPARSE_TAG_APPEXECLINK
# IO_REPARSE_TAG_CLOUD
# IO_REPARSE_TAG_CLOUD_1
# IO_REPARSE_TAG_CLOUD_2
# IO_REPARSE_TAG_CLOUD_3
# IO_REPARSE_TAG_CLOUD_4
# IO_REPARSE_TAG_CLOUD_5
# IO_REPARSE_TAG_CLOUD_6
# IO_REPARSE_TAG_CLOUD_7
# IO_REPARSE_TAG_CLOUD_8
# IO_REPARSE_TAG_CLOUD_9
# IO_REPARSE_TAG_CLOUD_A
# IO_REPARSE_TAG_CLOUD_B
# IO_REPARSE_TAG_CLOUD_C
# IO_REPARSE_TAG_CLOUD_D
# IO_REPARSE_TAG_CLOUD_E
# IO_REPARSE_TAG_CLOUD_F
# IO_REPARSE_TAG_CLOUD_MASK
# IO_REPARSE_TAG_CSV
# IO_REPARSE_TAG_DEDUP
# IO_REPARSE_TAG_DFS
# IO_REPARSE_TAG_DFSR
# IO_REPARSE_TAG_FILE_PLACEHOLDER
# IO_REPARSE_TAG_GLOBAL_REPARSE
# IO_REPARSE_TAG_HSM
# IO_REPARSE_TAG_HSM2
# IO_REPARSE_TAG_MOUNT_POINT
# IO_REPARSE_TAG_NFS
# IO_REPARSE_TAG_ONEDRIVE
# IO_REPARSE_TAG_PROJFS
# IO_REPARSE_TAG_PROJFS_TOMBSTONE
# IO_REPARSE_TAG_SIS
# IO_REPARSE_TAG_STORAGE_SYNC
# IO_REPARSE_TAG_SYMLINK
# IO_REPARSE_TAG_UNHANDLED
# IO_REPARSE_TAG_WCI
# IO_REPARSE_TAG_WCI_1
# IO_REPARSE_TAG_WCI_LINK
# IO_REPARSE_TAG_WCI_LINK_1
# IO_REPARSE_TAG_WCI_TOMBSTONE
# IO_REPARSE_TAG_WIM
# IO_REPARSE_TAG_WOF

# stx_mask;       /* Mask of bits indicating filled fields */
AC_CHECK_DECLS([
  STATX_TYPE,
  STATX_MODE,
  STATX_NLINK,
  STATX_UID,
  STATX_GID,
  STATX_ATIME,
  STATX_MTIME,
  STATX_CTIME,
  STATX_INO,
  STATX_SIZE,
  STATX_BLOCKS,
  STATX_BTIME,
  STATX_MNT_ID
  ], [], [], [[#include <linux/stat.h>]])

#### TODO: fields

# TODO: Solaris: char     st_fstype[_ST_FSTYPSZ]; /* Null-terminated type of filesystem */

# TODO: some way to test if we missed any fields
# TODO: non-stat_fields

# string user
# string group

# struct file_type const file_types = {
#   { "blk", S_IFBLK, BlockSpecial },
# };

# file_modes = {
#   { "rusr", S_IRUSR },
#   ...
# }

# enum flag_shift {
#   FLAG_SHIFT_COMPRESSED,
#   FLAG_SHIFT_END,
# };

# struct file_flag const file_flags = {
#   { "compressed", 1 << FLAG_SHIFT_COMPRESSED }
# };

# #if FLAG_SHIFT_END > 64
#   #error FOO
# #endif

####

#### chattr

# record file system type (btrfs,ext4,xfs)
# btrfs.5
#  attributes: chattr(1) or lsattr(1) utilities (the ioctls are FS_IOC_GETFLAGS and FS_IOC_SETFLAGS), due to the ioctl names the attributes are also called flags
# xflags: to distinguish from the previous, it’s extended flags, with tunable bits similar to the attributes but extensible and new bits will be added in the future (the ioctls are
#           FS_IOC_FSGETXATTR and FS_IOC_FSSETXATTR but they are not related to extended attributes that are also called xattrs), there’s no standard tool to change the bits, there’s support in xfs_io(8) as
#           command xfs_io -c chattr

# ext4.5
# xfs.5

#bsm/macos: chflags, specific ls flags
#Solaris: chmod[1] and ls[2]
#similar-sounding but unrelated commands: chatr (from HP-UX) and lsattr (from AIX)

#### SELinux

AC_CHECK_FUNCS([ \
  fgetfilecon \
  fgetfilecon_raw \
  getfilecon \
  getfilecon_raw \
  lgetfilecon \
  lgetfilecon_raw \
])

#### Extended attributes

AC_CHECK_FUNCS([ \
  listxattr \
  llistxattr \
  flistxattr \
])

#### ACLs

# acl(5)
AC_CHECK_FUNCS([ \
  acl_get_file \
])

#### Alternate Data Streams

# NTFS
# MacOS?

#### other

# https://en.wikipedia.org/wiki/File_attribute
# https://savannah.nongnu.org/projects/attr/
# https://www.gnu.org/software/gnulib/manual/gnulib.html#stat
# ST_NBLOCKSIZE ST_NBLOCKS (gnulib)
# get_birthtime (stat.c)
# get_stat_atime (stat.c)

#### Error string json:"error,omitempty"

#### Move the info from the shell variable `stat_fields` to substituted variables.

AC_MSG_NOTICE([defining STAT_FIELDS() with $stat_fields_count fields to be "$stat_fields"])

AC_SUBST([STAT_FIELDS], [$stat_fields])
AM_SUBST_NOTMAKE([STAT_FIELDS])

AC_SUBST([STAT_FIELDS_COUNT], [$stat_fields_count])
AM_SUBST_NOTMAKE([STAT_FIELDS_COUNT])

################

for i in src/fileinfo/*.h.in; do
  AC_CONFIG_FILES(${i%.in})
done
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([Doxyfile])
DX_MAN_FEATURE([ON])
DX_PDF_FEATURE([OFF])
DX_PS_FEATURE([OFF])
DX_INIT_DOXYGEN([fileinfo]) # TODO: optional
AC_OUTPUT
