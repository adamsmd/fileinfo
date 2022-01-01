# `fileinfo` - A file meta-data library

## Summary

### What?

Portable functions for collecting all the meta-data a file system has about a
file.

### Why?

So people implementing backup, archival or change tracking don't have to deal
with the subtleties in platform differences (e.g., `struct stat.gen` exists on
only some platforms) or in collecting *all* meta-data (e.g., the flags in
`FS_IOC_GETFLAGS`).

### When?

This library is still in development and is not yet functional.

### Where?

This library aims to support all platforms (within reason). Among others, this
includes:

- Linux
- Android
- FreeBSD
- OpenBSD
- NetBSD
- MacOS
- iOS
- Windows

See `PLATFORMS.md` for details.

### How?

The `./configure` script tests every known way to access
meta-data

### Who?

TODO: Who?

## Examples

TODO: dynamic examples

TODO: static examples

## Setup

TODO: setup

### Dependencies

TODO: dependencies

### Building

    bin/bootstrap
    ./configure
    make
    make check

The script `bin/clean` removes all generated files.

### Testing

TODO: testing

### Installation

TODO: installation

## Usage

TODO: usage
