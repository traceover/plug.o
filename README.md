# plug.o
Simple example that shows how to link static and dynamic libraries with GCC.

# Quick Start

`plug.o` uses the [nobuild](https://github.com/tsoding/nobuild) build system,
which requires only a C compiler to build your C project.
Even though we are using GCC which is only available on Linux so we aren't platform-independent.

```console
cc -o nobuild nobuild.c
./nobuild
./main_dynamic
./main_static
```
