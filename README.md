# `fileinfo` - A file meta-data library

## Summary

### What?

Portable functions for collecting all the meta-data a file system has about a
file (e.g., modification time).

### Why?

So other software implementing backup, archival or change tracking don't have to
deal with:

- the subtleties of platform differences (e.g., `struct stat.gen` exists on only
  some platforms),
- the difficulties in being sure one has collected *all* meta-data (e.g., the
  flags in `FS_IOC_GETFLAGS`, which are not in `struct stat`) or
- the challenges of testing this on all the different platforms.

### When?

This library is still in development and is not yet functional.

### Where?

This library aims to support all platforms within reason. Among others, this
includes:

- Linux
- Windows
- MacOS
- Android
- iOS
- BSD (FreeBSD, OpenBSD, NetBSD, etc.)

Towards this goal, this library uses [GitHub
Actions](https://github.com/adamsmd/fileinfo/actions) to test as many
platform configurations as possible.

### How?

The `./configure` script tests various ways to access file meta-data. Functions
are then exposed for retrieving this data (see `src/fileinfo.c`) and structs and
macros are defined for accessing parts of this meta-data (see
`src/fileinfo/static.h.in`).

Information about how these meta-data parts are laid out in memory is also
exposed (see `src/fileinfo/dynamic.h`), so users of this library can do things
like platform-oblivious serialization.  See `tests/fileinfo-file-dynamic.c` for
an example.

### Who?

TODO: Who?
Pass the torch
Distro (dpkg)

## Examples

See `tests/fileinfo-fields-dynamic.c` for an example program that prints all
known attributes.

TODO: static examples

```C
TODO: s.nsec
```

TODO: Regardless of where nsec is located

## Setup

TODO: setup

### Dependencies

TODO: dependencies

### Building

```Shell
bin/bootstrap # needed only if you don't have ./configure, Makefile, etc.
./configure
make
make check
make install
```

The script `bin/clean` removes all generated files.

### Testing

TODO: testing

### Installation

TODO: installation

## Usage

TODO: usage
