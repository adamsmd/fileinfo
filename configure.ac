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
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_PROG_CXX

#### Checks for libraries.

#### Checks for header files.
AC_HEADER_ASSERT
AC_HEADER_MAJOR
AC_HEADER_STDBOOL

AC_CHECK_HEADERS([ \
  linux/fcntl.h \
  linux/stat.h \
  stddef.h \
  sys/stat.h \
  unistd.h \
])

#### Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_TYPE([struct statx], [use_statx=yes], [], [[#include <linux/stat.h>]])
AC_CHECK_TYPE([struct stat], [use_stat=yes], [], [[#include <sys/stat.h>]])
AC_CHECK_TYPES([ \
  ptrdiff_t \
])

#### Checks for library functions.
AC_CHECK_FUNCS([ \
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

AX_APPEND_FLAG([-fanalyzer], [AM_CFLAGS])
AX_APPEND_FLAG([-Wanalyzer-too-complex], [AM_CFLAGS])

AX_APPEND_FLAG([-pedantic], [AM_CFLAGS])

# -pedantic-errors

# -Wctor-dtor-privacy
# -Weffc++
# -Wnoexcept
# -Wold-style-cast
# -Wsign-promo
# -Wstrict-null-sentinel


#### AX_APPEND_FLAG([-fsyntax-only], [AM_CFLAGS])
#### AX_APPEND_FLAG([-fmax-errors=n], [AM_CFLAGS])
AX_APPEND_FLAG([-Wpedantic], [AM_CFLAGS])
#### AX_APPEND_FLAG([-pedantic-errors], [AM_CFLAGS])
#### AX_APPEND_FLAG([-w], [AM_CFLAGS])
AX_APPEND_FLAG([-Wextra], [AM_CFLAGS])
AX_APPEND_FLAG([-Wall], [AM_CFLAGS])
AX_APPEND_FLAG([-Wabi], [AM_CFLAGS])
##AX_APPEND_FLAG([-Wabi=n], [AM_CFLAGS])
AX_APPEND_FLAG([-Waddress], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-address-of-packed-member], [AM_CFLAGS])
AX_APPEND_FLAG([-Waggregate-return], [AM_CFLAGS])
AX_APPEND_FLAG([-Walloc-size-larger-than=1024], [AM_CFLAGS])
AX_APPEND_FLAG([-Walloc-zero], [AM_CFLAGS])
AX_APPEND_FLAG([-Walloca], [AM_CFLAGS])
AX_APPEND_FLAG([-Walloca-larger-than=1024], [AM_CFLAGS])
AX_APPEND_FLAG([-Wno-aggressive-loop-optimizations], [AM_CFLAGS])
AX_APPEND_FLAG([-Warith-conversion], [AM_CFLAGS])
AX_APPEND_FLAG([-Warray-bounds], [AM_CFLAGS])
AX_APPEND_FLAG([-Warray-bounds=2], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-attributes], [AM_CFLAGS])
AX_APPEND_FLAG([-Wattribute-alias=2], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-attribute-alias], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-attribute-warning], [AM_CFLAGS])
AX_APPEND_FLAG([-Wbool-compare], [AM_CFLAGS])
AX_APPEND_FLAG([-Wbool-operation], [AM_CFLAGS])
AX_APPEND_FLAG([-Wno-builtin-declaration-mismatch], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-builtin-macro-redefined], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc90-c99-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc99-c11-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc11-c2x-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc++-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc++11-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc++14-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc++17-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wc++20-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wcast-align], [AM_CFLAGS])
AX_APPEND_FLAG([-Wcast-align=strict], [AM_CFLAGS])
AX_APPEND_FLAG([-Wcast-function-type], [AM_CFLAGS])
AX_APPEND_FLAG([-Wcast-qual], [AM_CFLAGS]) ####
AX_APPEND_FLAG([-Wchar-subscripts], [AM_CFLAGS])
AX_APPEND_FLAG([-Wclobbered], [AM_CFLAGS])
AX_APPEND_FLAG([-Wcomment], [AM_CFLAGS])
AX_APPEND_FLAG([-Wconversion], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-coverage-mismatch], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-cpp], [AM_CFLAGS])
AX_APPEND_FLAG([-Wdangling-else], [AM_CFLAGS])
AX_APPEND_FLAG([-Wdate-time], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-deprecated], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-deprecated-declarations], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-designated-init], [AM_CFLAGS])
AX_APPEND_FLAG([-Wdisabled-optimization], [AM_CFLAGS]) ####
#### AX_APPEND_FLAG([-Wno-discarded-array-qualifiers], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-discarded-qualifiers], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-div-by-zero], [AM_CFLAGS])
AX_APPEND_FLAG([-Wdouble-promotion], [AM_CFLAGS])
AX_APPEND_FLAG([-Wduplicated-branches], [AM_CFLAGS])
AX_APPEND_FLAG([-Wduplicated-cond], [AM_CFLAGS])
AX_APPEND_FLAG([-Wempty-body], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-endif-labels], [AM_CFLAGS])
AX_APPEND_FLAG([-Wenum-compare], [AM_CFLAGS])
AX_APPEND_FLAG([-Wenum-conversion], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Werror], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Werror=*], [AM_CFLAGS])
AX_APPEND_FLAG([-Wexpansion-to-defined], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wfatal-errors], [AM_CFLAGS])
AX_APPEND_FLAG([-Wfloat-conversion], [AM_CFLAGS])
AX_APPEND_FLAG([-Wfloat-equal], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat=2], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-format-contains-nul], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-format-extra-args], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-nonliteral], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-overflow=2], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-security], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-signedness], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-truncation=2], [AM_CFLAGS])
AX_APPEND_FLAG([-Wformat-y2k], [AM_CFLAGS])
AX_APPEND_FLAG([-Wframe-address], [AM_CFLAGS])
AX_APPEND_FLAG([-Wframe-larger-than=1024], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-free-nonheap-object], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-if-not-aligned], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-ignored-attributes], [AM_CFLAGS])
AX_APPEND_FLAG([-Wignored-qualifiers], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-incompatible-pointer-types], [AM_CFLAGS])
AX_APPEND_FLAG([-Wimplicit], [AM_CFLAGS])
AX_APPEND_FLAG([-Wimplicit-fallthrough], [AM_CFLAGS])
AX_APPEND_FLAG([-Wimplicit-fallthrough=5], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-implicit-function-declaration], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-implicit-int], [AM_CFLAGS])
AX_APPEND_FLAG([-Winit-self], [AM_CFLAGS])
AX_APPEND_FLAG([-Winline], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-int-conversion], [AM_CFLAGS])
AX_APPEND_FLAG([-Wint-in-bool-context], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-int-to-pointer-cast], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-invalid-memory-model], [AM_CFLAGS])
AX_APPEND_FLAG([-Winvalid-pch], [AM_CFLAGS])
AX_APPEND_FLAG([-Wjump-misses-init], [AM_CFLAGS])
AX_APPEND_FLAG([-Wlarger-than=4096], [AM_CFLAGS])
AX_APPEND_FLAG([-Wlogical-not-parentheses], [AM_CFLAGS])
AX_APPEND_FLAG([-Wlogical-op], [AM_CFLAGS])
AX_APPEND_FLAG([-Wlong-long], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-lto-type-mismatch], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmain], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmaybe-uninitialized], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmemset-elt-size], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmemset-transposed-args], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmisleading-indentation], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-attributes], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-braces], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-field-initializers], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-format-attribute], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-include-dirs], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmissing-noreturn], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-missing-profile], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-multichar], [AM_CFLAGS])
AX_APPEND_FLAG([-Wmultistatement-macros], [AM_CFLAGS])
AX_APPEND_FLAG([-Wnonnull], [AM_CFLAGS])
AX_APPEND_FLAG([-Wnonnull-compare], [AM_CFLAGS])
AX_APPEND_FLAG([-Wnormalized=nfkc], [AM_CFLAGS])
AX_APPEND_FLAG([-Wnull-dereference], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-odr], [AM_CFLAGS])
AX_APPEND_FLAG([-Wopenmp-simd], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-overflow], [AM_CFLAGS])
AX_APPEND_FLAG([-Woverlength-strings], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-override-init-side-effects], [AM_CFLAGS])
AX_APPEND_FLAG([-Wpacked], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-packed-bitfield-compat], [AM_CFLAGS])
AX_APPEND_FLAG([-Wpacked-not-aligned], [AM_CFLAGS])
AX_APPEND_FLAG([-Wpadded], [AM_CFLAGS])
AX_APPEND_FLAG([-Wparentheses], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-pedantic-ms-format], [AM_CFLAGS])
AX_APPEND_FLAG([-Wpointer-arith], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-pointer-compare], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-pointer-to-int-cast], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-pragmas], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-prio-ctor-dtor], [AM_CFLAGS])
AX_APPEND_FLAG([-Wredundant-decls], [AM_CFLAGS])
AX_APPEND_FLAG([-Wrestrict], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-return-local-addr], [AM_CFLAGS])
AX_APPEND_FLAG([-Wreturn-type], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-scalar-storage-order], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsequence-point], [AM_CFLAGS])
AX_APPEND_FLAG([-Wshadow], [AM_CFLAGS])
AX_APPEND_FLAG([-Wshadow=global], [AM_CFLAGS])
## AX_APPEND_FLAG([-Wshadow=local], [AM_CFLAGS])
## AX_APPEND_FLAG([-Wshadow=compatible-local], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-shadow-ivar], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-shift-count-negative], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-shift-count-overflow], [AM_CFLAGS])
AX_APPEND_FLAG([-Wshift-negative-value], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-shift-overflow], [AM_CFLAGS])
AX_APPEND_FLAG([-Wshift-overflow=1], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsign-compare], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsign-conversion], [AM_CFLAGS]) ####
#### AX_APPEND_FLAG([-Wno-sizeof-array-argument], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsizeof-array-div], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsizeof-pointer-div], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsizeof-pointer-memaccess], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstack-protector], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstack-usage=1024], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstrict-aliasing], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstrict-aliasing=3], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstrict-overflow], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstrict-overflow=5], [AM_CFLAGS])
AX_APPEND_FLAG([-Wstring-compare], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-stringop-overflow], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-stringop-overread], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-stringop-truncation], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsuggest-attribute=pure], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsuggest-attribute=const], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsuggest-attribute=noreturn], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsuggest-attribute=format], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsuggest-attribute=malloc], [AM_CFLAGS])
AX_APPEND_FLAG([-Wswitch], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-switch-bool], [AM_CFLAGS])
AX_APPEND_FLAG([-Wswitch-default], [AM_CFLAGS])
AX_APPEND_FLAG([-Wswitch-enum], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-switch-outside-range], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-switch-unreachable], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsync-nand], [AM_CFLAGS])
AX_APPEND_FLAG([-Wsystem-headers], [AM_CFLAGS])
AX_APPEND_FLAG([-Wtautological-compare], [AM_CFLAGS])
AX_APPEND_FLAG([-Wtrampolines], [AM_CFLAGS])
AX_APPEND_FLAG([-Wtrigraphs], [AM_CFLAGS])
AX_APPEND_FLAG([-Wtsan], [AM_CFLAGS])
AX_APPEND_FLAG([-Wtype-limits], [AM_CFLAGS])
AX_APPEND_FLAG([-Wundef], [AM_CFLAGS])
AX_APPEND_FLAG([-Wuninitialized], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunknown-pragmas], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunsuffixed-float-constants], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-but-set-parameter], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-but-set-variable], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-const-variable], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-const-variable=2], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-function], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-label], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-local-typedefs], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-macros], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-parameter], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-unused-result], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-value], [AM_CFLAGS])
AX_APPEND_FLAG([-Wunused-variable], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-varargs], [AM_CFLAGS])
AX_APPEND_FLAG([-Wvariadic-macros], [AM_CFLAGS])
AX_APPEND_FLAG([-Wvector-operation-performance], [AM_CFLAGS])
AX_APPEND_FLAG([-Wvla], [AM_CFLAGS])
AX_APPEND_FLAG([-Wvla-larger-than=1024], [AM_CFLAGS])
#### AX_APPEND_FLAG([-Wno-vla-larger-than], [AM_CFLAGS])
AX_APPEND_FLAG([-Wvolatile-register-var], [AM_CFLAGS])
AX_APPEND_FLAG([-Wwrite-strings], [AM_CFLAGS])
AX_APPEND_FLAG([-Wzero-length-bounds], [AM_CFLAGS])

################
# Populate `stat_fields` with data about the fields available in `struct stat` or `struct statx`

#### Helpers

AH_TEMPLATE([USE_STATX], [Define to 1 if we should use the `statx' function.])
AH_TEMPLATE([USE_STAT], [Define to 1 if we should use the `stat' function.])
AS_IF(
  [test "x$use_statx" = xyes], [
    AC_DEFINE(USE_STATX, 1)
    declare_fileinfo_stat="
[#include <linux/stat.h>]
[typedef struct statx fileinfo_stat;]
      "],
  [test "x$use_stat" = xyes], [
    AC_DEFINE(USE_STAT, 1)
    declare_fileinfo_stat="
[#include <sys/stat.h>]
[typedef struct stat fileinfo_stat;]
      "],
  [AC_MSG_ERROR([cannot find `struct stat`])])
AC_SUBST([DECLARE_FILEINFO_STAT],["$declare_fileinfo_stat"])
AM_SUBST_NOTMAKE([DECLARE_FILEINFO_STAT])
preamble="
AC_INCLUDES_DEFAULT
$declare_fileinfo_stat
"

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

# DEFUNX(NAME, STATX, STAT)
# --------------------------------------
# Define an autoconf macro NAME to call STATX if `struct statx` exists.
# Otherwise, have it call STAT.
AC_DEFUN([DEFUNX],[
  m4_define([$1], [AS_IF([test "x$use_statx" = xyes], [$2], [$3])])
]) # DEFUNX

#### File type and mode

# TODO: stx_mode/st_mode is handled specially

#### Unsigned integer fields

# CHECK_STATX(NAME)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_INT(stx_NAME)
# - F_INT(st_NAME)
DEFUNX([CHECK_STATX],
  [CHECK_STAT([F_INT], stx_$1, [$1])],
  [CHECK_STAT([F_INT], st_$1, [$1])]
) # CHECK_STATX

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

#### Device fields

# CHECK_DEV(NAME)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_DEV(stx_NAME_major, NAME, stx_NAME_major, stx_NAME_minor)
# - F_DEV(stx_NAME, NAME, stx_NAME, stx_NAME)
DEFUNX([CHECK_DEV],
  [CHECK_STAT([F_DEV], stx_$1_major, [$1, stx_$1_major, stx_$1_minor])],
  [CHECK_STAT([F_DEV], st_$1,        [$1, st_$1, st_$1])],
) # CHECK_DEV

CHECK_DEV(dev)  # ID of device containing file
CHECK_DEV(rdev) # Device ID (if special file)

#### Time fields (seconds)

# CHECK_TIME_SEC(PREFIX)
# --------------------------------------
# Add one or none of the following to `stat_fields` based on what fields exist.
# - F_TIME_SEC(stx_PREFIXtime.tv_sec, PREFIXtime_sec)
# - F_TIME_SEC(st_PREFIXtime, PREFIXtime_sec)
DEFUNX([CHECK_TIME_SEC],
  [CHECK_STAT([F_TIME_SEC], stx_$1time.tv_sec, [$1time_sec])],
  [CHECK_STAT([F_TIME_SEC], st_$1time,         [$1time_sec])],
) # CHECK_TIME_SEC

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
AC_DEFUN([CHECK_TIME_NSEC],[
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

# TODO: Solaris: char     st_fstype[_ST_FSTYPSZ]; /* Null-terminated type of filesystem */

# TODO: linux mnt_id

# TODO: struct statx.stx_mask
# TODO: struct statx.stx_attributes

# TODO: some way to test if we missed any fields
# TODO: non-stat_fields


#### Move the info from the shell variable `stat_fields` to the CPP macro `STAT_FIELDS()`.

AC_MSG_NOTICE([defining STAT_FIELDS() with $stat_fields_count fields to be "$stat_fields"])

AH_TEMPLATE([STAT_FIELDS_COUNT],[Define to be the number of fields in STAT_FIELDS().])
AC_DEFINE_UNQUOTED([STAT_FIELDS_COUNT], [$stat_fields_count])

AH_TEMPLATE([STAT_FIELDS],[Define to be the fields in `struct statx` or `struct stat`.])
AC_DEFINE_UNQUOTED([STAT_FIELDS(F_INT,F_DEV,F_TIME_SEC,F_TIME_NSEC)], [$stat_fields])

################

for i in src/fileinfo/*.h.in; do
  AC_CONFIG_FILES(${i%.in})
done
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
