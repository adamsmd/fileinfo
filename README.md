# libstat

## What?

Portable functions for collecting all of the meta-data stored about a file in a filesystem.

## Why?

Backup, archival and change tracking

## Building

    ./configure
    make
    make check

The script `./autoclean.sh` removes all generated files.

The script `./autogen.sh` generates all generated files.

## Supported Platforms

Minix:
  <https://man.minix3.org/cgi-bin/man.cgi?query=stat&apropos=0&sektion=2>
AIX:
  <https://www.ibm.com/docs/en/aix/7.3?topic=s-stat-fstat-lstat-statx-fstatx-statxat-fstatat-fullstat-ffullstat-stat64-fstat64-lstat64-stat64x-fstat64x-lstat64x-stat64xat-subroutine>
  <https://www.ibm.com/docs/en/aix/7.3?topic=files-stath-file>
Oracle Solaris:
  <https://docs.oracle.com/cd/E26502_01/html/E29032/stat-2.html>
macOS:
  <https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/stat.2.html>
NetBSD:
  <https://man.netbsd.org/stat.2>
OpenBSD:
  <https://man.openbsd.org/stat.2>
FreeBSD:
  <https://www.freebsd.org/cgi/man.cgi?query=stat&apropos=0&sektion=2>
Linux:
  <https://man7.org/linux/man-pages/man2/fstat64.2.html>
  <https://man7.org/linux/man-pages/man2/statx.2.html>
Windows:
  <https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/stat-functions?view=msvc-170>

### Other Documentation

<https://www.unix.com/man-page-repository.php>

<https://hub.docker.com/search?type=image&category=os>

<https://github.com/orgs/vmactions/repositories?type=source>
