# Potential Platforms

## Platform Requirements

Note that these requirements are driven by practicality more than by any
particular philosophical position.

- Be testable (currently via GitHub Actions)
- Be able to (somehow) run './configure'
- Be able to (somehow) run 'make'
- Have a notion of filename as a `char*`

Platforms may be cut if their maintenance cost is too high relative to their
usage.

## Potential Platform

Many of these are impractical.  The purpose of listing them is to ensure we
consider them all.

Check marks in the following indicate we have GitHub Actions for testing these,
not that they work and are fully implemented.

- [x] Unix
  - [ ] QNX
  - [ ] Minix
  - [x] Linux
    - [x] Chrome OS
    - [ ] SE Linux
    - [x] Arch
    - [x] Gentoo
    - [x] Debian
      - [x] Ubuntu
        - [ ] Mint
      - [ ] ~~gLinux~~ (No public releases)
      - [ ] ~~Goobuntu~~ (No public releases)
    - [x] Fedora
      - [x] CentOS
    - [x] openSUSE
    - [ ] SUSE Linux Enterprise <https://www.suse.com/download/sles/>
    - [ ] nixOS
    - [x] OpenWRT
    - [x] Android
      - [ ] WearOS
      - [ ] Android-x86
        - [ ] Android TV x86
  - [x] BSD
    - [x] FreeBSD
      - [ ] ? GhostBSD
      - [ ] ? DragonFlyBSD
      - [ ] ? TrueOS
      - [ ] ? DragonFlyBSD
      - [ ] ? OSv
    - [x] NetBSD
      - [x] OpenBSD
    - [x] Darwin
      - [x] macOS
      - [ ] macOS Server
      - [x] iOS
        - [ ] watchOS
        - [ ] tvOS
        - [ ] iPadOS
  - [ ] GNU/Hurd
  - [ ] SunOS
  - [ ] Xenix (Microsoft)
  - [x] Solaris
    - [ ] Oracle Solaris
    - [ ] OpenSolaris
      - [ ] OpenIndiana
      - [ ] illumos
      - [ ] SmartOS
  - [ ] HP-UX
  - [ ] IBM AIX
  - [ ] Irix
  - [ ] Redox
  - [ ] Cray
- [x] Windows
  - [ ] Win16
  - [ ] Win32
  - [ ] Win64
  - [ ] WinNT
    - [ ] Windows 7
    - [ ] Windows 10
    - [x] Windows Server
      - [ ] ReactOS
- [ ] DOS
  - [ ] MS-DOS 1.25 (FOSS)
  - [ ] MS-DOS 2.0 (FOSS)
  - [ ] FreeDOS
  - [ ] QDOS
  - [ ] OpenDOS
  - [ ] PC DOS
- [ ] BareMetal <https://en.wikipedia.org/wiki/BareMetal>
- [ ] Fuchsia <https://en.wikipedia.org/wiki/Fuchsia_(operating_system)>
- [ ] L4
  - [ ] SeL4
- [ ] Mach
- [ ] Cosmos
- [ ] ITS <https://github.com/PDP-10/its>
- [ ] Plan 9
  - [ ] Inferno
- [ ] VxWorks
- [ ] PhantomOS
- [ ] RISC OS
- [ ] BeOS
  - [ ] Haiku
- [ ] Genode
- [ ] VMS/VAX
  - [ ] OpenVMS
  - [ ] PDP-11
- [ ] AmigaOS
  - [ ] AROS
  - [ ] Syllable Desktop
  - [ ] MorphOS
- [ ] Multics
- [ ] OpenServer
- [ ] OS/2
  - [ ] AcraOS
- [ ] Singularity
- [ ] BlackBerry

## Platform Documentation

- Minix
  - <https://man.minix3.org/cgi-bin/man.cgi?query=stat&apropos=0&sektion=2>
- AIX
  - <https://www.ibm.com/docs/en/aix/7.3?topic=s-stat-fstat-lstat-statx-fstatx-statxat-fstatat-fullstat-ffullstat-stat64-fstat64-lstat64-stat64x-fstat64x-lstat64x-stat64xat-subroutine>
  - <https://www.ibm.com/docs/en/aix/7.3?topic=files-stath-file>
- Oracle Solaris
  - <https://docs.oracle.com/cd/E26502_01/html/E29032/stat-2.html>
- macOS
  - <https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/stat.2.html>
- NetBSD
  - <https://man.netbsd.org/stat.2>
- OpenBSD
  - <https://man.openbsd.org/stat.2>
- FreeBSD
  - <https://www.freebsd.org/cgi/man.cgi?query=stat&apropos=0&sektion=2>
- Linux
  - <https://man7.org/linux/man-pages/man2/fstat64.2.html>
  - <https://man7.org/linux/man-pages/man2/statx.2.html>
- Windows
  - <https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/stat-functions?view=msvc-170>

Other platform documentation sources: <https://www.unix.com/man-page-repository.php>

## Similar Systems

- Apache Portable Runtime (APR)
  - <https://github.com/traviscross/apr/blob/05266ad52ef0c1848a81b21705b9f13fc8f7028b/file_io/unix/filestat.c>
- Java
  - <https://docs.oracle.com/javase/tutorial/essential/io/fileAttr.html>
    - <https://docs.oracle.com/javase/8/docs/api/java/nio/file/attribute/PosixFileAttributeView.html>
    - <https://docs.oracle.com/javase/8/docs/api/java/nio/file/attribute/AclFileAttributeView.html>
    - <https://docs.oracle.com/javase/8/docs/api/java/nio/file/attribute/UserDefinedFileAttributeView.html>
  - <https://docs.oracle.com/javase/7/docs/api/java/nio/file/attribute/package-summary.html>
  - <https://github.com/openjdk/jdk/blob/739769c8fc4b496f08a92225a12d07414537b6c0/src/java.base/share/classes/java/nio/file/attribute/PosixFileAttributes.java>
  - <https://github.com/openjdk/jdk/blob/739769c8fc4b496f08a92225a12d07414537b6c0/src/java.base/linux/classes/sun/nio/fs/LinuxFileStore.java>
  - <https://github.com/openjdk/jdk/blob/739769c8fc4b496f08a92225a12d07414537b6c0/src/java.base/share/classes/java/nio/file/attribute/package-info.java>
  - <https://github.com/openjdk/jdk/blob/6765f90250/src/java.base/unix/classes/sun/nio/fs/UnixNativeDispatcher.java>
  - <https://github.com/openjdk/jdk/blob/739769c8fc4b496f08a92225a12d07414537b6c0/src/java.base/unix/native/libnio/ch/FileKey.c>
  - <https://github.com/openjdk/jdk/blob/3d7671b65e/src/java.base/share/native/libnio/nio_util.c>
  - <https://github.com/openjdk/jdk/blob/739769c8fc/src/java.base/share/classes/java/nio/file/attribute/PosixFileAttributes.java>
  - <https://github.com/openjdk/jdk/blob/fd4de1ed404640ee0e744f022bbfa89db200ef05/src/java.base/unix/classes/sun/nio/fs/UnixFileSystemProvider.java>
  - <https://github.com/openjdk/jdk/blob/739769c8fc4b496f08a92225a12d07414537b6c0/src/java.base/share/classes/java/nio/file/attribute/AclFileAttributeView.java>
  - <https://github.com/openjdk/jdk/blob/6765f902505fbdd02f25b599f942437cd805cad1/src/java.base/unix/classes/sun/nio/fs/UnixFileAttributeViews.java>
  - <https://github.com/openjdk/jdk/blob/d1cad2463a3f70d4ff9246d5bbae268bfa6717d7/src/java.base/share/classes/java/nio/file/Files.java>
- Go
  - <https://github.com/golang/go/search?q=nlink>
    - <https://github.com/golang/go/blob/2ebe77a2fda1ee9ff6fd9a3e08933ad1ebaea039/api/go1.12.txt>
    - <https://github.com/golang/go/blob/f229e7031a6efb2f23241b5da000c3b3203081d6/src/syscall/syscall_linux_mips64x.go>
    - <https://github.com/golang/go/blob/6e81f78c0f1653ea140e6c8d008700ddad1fa0a5/api/except.txt>
    - <https://github.com/golang/go/blob/2ebe77a2fda1ee9ff6fd9a3e08933ad1ebaea039/src/runtime/defs1_solaris_amd64.go>
- <https://github.com/tklauser/statx/blob/master/statx.go>
- <https://github.com/whotwagner/statx-fun>
- <https://github.com/ckarageorgkaneen/pystatx>
- <https://github.com/boostorg/filesystem/blob/0f695acdf96ac1e3664085e1d4813f828387b845/src/operations.cpp>
  - <https://github.com/boostorg/filesystem/blob/0f695acdf96ac1e3664085e1d4813f828387b845/include/boost/filesystem/file_status.hpp>
- <https://pypi.org/project/statx/>
- <https://pkg.go.dev/github.com/gentlemanautomaton/volmgmt/fileattr>
- <https://pkg.go.dev/github.com/splace/os/xattribs>
- <https://pkg.go.dev/github.com/bsm/arff>
- Android
  - <https://developer.android.com/reference/android/system/Os#fstat(java.io.FileDescriptor)>
  - <https://developer.android.com/reference/android/system/Os>