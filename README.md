# `libstat`

## What?

Portable functions for collecting all the meta-data a file system has about a file.

## Why?

Backup, archival and change tracking

## How?

TODO: How?

## Where?

TODO: Where?

## Who?

TODO: Who?

## When?

TODO: When?

## Examples

TODO: examples

## Setup

TODO: setup

### Dependencies

TODO: dependencies

### Building

    bin/bootstrap
    ./configure
    make
    make check

The script `bin/clean-all` removes all generated files.

### Testing

TODO: testing

### Installation

TODO: installation

## Usage

TODO: usage

## Supported Platforms

- Minix:
  - <https://man.minix3.org/cgi-bin/man.cgi?query=stat&apropos=0&sektion=2>
- AIX:
  - <https://www.ibm.com/docs/en/aix/7.3?topic=s-stat-fstat-lstat-statx-fstatx-statxat-fstatat-fullstat-ffullstat-stat64-fstat64-lstat64-stat64x-fstat64x-lstat64x-stat64xat-subroutine>
  - <https://www.ibm.com/docs/en/aix/7.3?topic=files-stath-file>
- Oracle Solaris:
  - <https://docs.oracle.com/cd/E26502_01/html/E29032/stat-2.html>
- macOS:
  - <https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/stat.2.html>
- NetBSD:
  - <https://man.netbsd.org/stat.2>
- OpenBSD:
  - <https://man.openbsd.org/stat.2>
- FreeBSD:
  - <https://www.freebsd.org/cgi/man.cgi?query=stat&apropos=0&sektion=2>
- Linux:
  - <https://man7.org/linux/man-pages/man2/fstat64.2.html>
  - <https://man7.org/linux/man-pages/man2/statx.2.html>
- Windows:
  - <https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/stat-functions?view=msvc-170>

Other patform documentation sources: <https://www.unix.com/man-page-repository.php>

## Similar Projects

- Apache Portable Runtime (APR)
  - e.g., <https://github.com/traviscross/apr/blob/05266ad52ef0c1848a81b21705b9f13fc8f7028b/file_io/unix/filestat.c>
