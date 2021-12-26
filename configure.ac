#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([fileinfo], [0.1.0], [https://github.com/adamsmd/fileinfo])
AC_CONFIG_SRCDIR([src/fileinfo.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])

################
# Standard sections

#### Checks for programs.
AM_PROG_AR
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB

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

################
# Populate `stat_fields` with data about the fields available in `struct stat` or `struct statx`

#### Helpers

AH_TEMPLATE([USE_STATX], [Define to 1 if we should use the `statx' function.])
AH_TEMPLATE([USE_STAT], [Define to 1 if we should use the `stat' function.])
AS_IF(
  [test "x$use_statx" = xyes], [
    AC_DEFINE(USE_STATX, 1)
    preamble="
      AC_INCLUDES_DEFAULT
      [#include <linux/stat.h>]
      [typedef struct statx struct_stat;]
      "],
  [test "x$use_stat" = xyes], [
    AC_DEFINE(USE_STAT, 1)
    preamble="
      AC_INCLUDES_DEFAULT
      [typedef struct stat struct_stat;]
      "],
  [AC_MSG_ERROR([cannot find `struct stat`])])

# Shell variable holding the CPP macro invocations to be added to the CPP macro `STAT_FIELDS()`
stat_fields=
stat_fields_count=0

# CHECK_STAT(MACRO, FIELD, ARGS...)
# --------------------------------------
# If FIELD is a member of `struct_stat`, add `MACRO(FIELD, ARGS...)` to
# `stat_fields`.
AC_DEFUN([CHECK_STAT], [
  AC_CHECK_MEMBER([struct_stat.$2],
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

# TODO: st_mode is universal so we handle it specially

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

CHECK_STATX(ino)
CHECK_STATX(nlink)
CHECK_STATX(uid)
CHECK_STATX(gid)
CHECK_STATX(size)
CHECK_STATX(blksize)
CHECK_STATX(blocks)
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

CHECK_DEV(dev)
CHECK_DEV(rdev)

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
  CHECK_STAT([F_TIME_NSEC], st_$1time_n, [$1time_nsec]) # aix
  CHECK_STAT([F_TIME_NSEC], st_$1timespec.tv_nsec, [$1time_nsec]) # macOS
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

AC_MSG_NOTICE([defining STAT_FIELDS() with $stat_fields_count fields to be "$stat_fields"])

# TODO: NOTE: AC_COMPUTE_INT

#### Move the info from the shell variable `stat_fields` to the CPP macro `STAT_FIELDS()`.

AH_TEMPLATE([STAT_FIELDS_COUNT],[Define to be the number of fields in STAT_FIELDS().])
AC_DEFINE_UNQUOTED([STAT_FIELDS_COUNT], [$stat_fields_count])

AH_TEMPLATE([STAT_FIELDS],[Define to be the fields in `struct statx` or `struct stat`.])
AC_DEFINE_UNQUOTED([STAT_FIELDS(F_INT,F_DEV,F_TIME_SEC,F_TIME_NSEC)], [$stat_fields])

for i in src/fileinfo/*.h.in; do
  AC_CONFIG_FILES(${i%.in})
done

################

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
