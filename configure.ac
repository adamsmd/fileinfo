#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libstat], [0.1.0], [https://github.com/adamsmd/libstat])
AC_CONFIG_SRCDIR([src/stat.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])

################
# Utility functions

# TODO: eliminate?
AC_DEFUN([LINES],[m4_joinall(m4_newline,"$@")])
AC_DEFUN([PREAMBLE],[LINES(AC_INCLUDES_DEFAULT(),$@)])

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
AC_CHECK_TYPE([struct statx], [have_statx=yes], [], [[#include <linux/stat.h>]])
AC_CHECK_TYPE([struct stat], [have_stat=yes], [], [[#include <sys/stat.h>]])

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

stat_fields=

#### Helpers

AS_IF(
  [test "x$have_statx" = xyes],
    [preamble=PREAMBLE([#include <linux/stat.h>],[typedef struct statx struct_stat;])],
  [test "x$have_stat" = xyes],
    [preamble=PREAMBLE([typedef struct stat struct_stat;])],
  [AC_MSG_ERROR([cannot find `struct stat`])])

# TODO: document
# STAT_FIELD(name)
# --------------------------------------
AC_DEFUN([CHECK_STAT],[
  AC_CHECK_MEMBER(struct_stat.$2,
    [AS_VAR_APPEND(stat_fields, LINES([ \\],[  $1($2, $3)]))],
    [],
    [$preamble])
]) # CHECK_STAT

AC_DEFUN([DEFUNX],[
  m4_define([$1], [AS_IF([test "x$have_statx" = xyes], [$2], [$3])])
]) # DEFUNX

#### File type and mode

# TODO: st_mode is universal so we handle it specially

#### Unsigned integer fields

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

DEFUNX([CHECK_DEV],
  [CHECK_STAT([F_DEV], stx_$1_major, [$1, stx_$1_major, stx_$1_minor])],
  [CHECK_STAT([F_DEV], st_$1,        [$1, st_$1, st_$1])],
) # CHECK_DEV

CHECK_DEV(dev)
CHECK_DEV(rdev)

#### Time fields (seconds)

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

# STAT_FIELD(type) # AIX (vnode type, enum)
# STAT_FIELD(vfstype) # AIX (enum)
# STAT_FIELD(flag) # AIX (enum)

#### Bit-flag fields

# STAT_FIELD(flags) # macOS NetBSD OpenBSD FreeBSD (flags)

# Solaris
# char     st_fstype[_ST_FSTYPSZ]; /* Null-terminated type of filesystem */

# TODO: linux mnt_id

##### AC_CHECK_MEMBERS([struct statx.stx_mask], [], [], [[#include <linux/stat.h>]])
    # AC_CHECK_MEMBERS([struct statx.stx_attributes], [], [], [[#include <linux/stat.h>]])

# TODO typedef struct_stat
# TODO: define stat_atime_sec stx_atime.tv_nsec

# TODO: if HAVE_STATX make_dev(base)

echo "<<$stat_fields>>"

# TODO: NOTE: AC_COMPUTE_INT

#### Move the info from `$stat_fields` to the CPP macro `STAT_FIELDS()`.

AC_DEFINE_UNQUOTED([STAT_FIELDS(F_INT,F_DEV,F_TIME_SEC,F_TIME_NSEC)], [$stat_fields], [TODO:description])

################

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
