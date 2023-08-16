# plug.o
Simple example that shows how to link static and dynamic libraries with GCC.

## Quick Start

`plug.o` uses the [nobuild](https://github.com/tsoding/nobuild) build system,
which requires only a C compiler to build your C project.
Even though we are using GCC which is only available on Linux so we aren't platform-independent.

Check out `nobuild.c` to understand what it does and then run the build system to test it.

```console
cc -o nobuild nobuild.c
./nobuild
```
