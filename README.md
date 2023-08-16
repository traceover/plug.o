# plug.o
Simple example that shows how to link static and dynamic libraries with gcc

# Quick Start

`plug.o` uses the [nobuild](https://github.com/tsoding/nobuild) build system,
which requires only a C compiler to build your project.
Even though we are using GCC which is only available on linux so we aren't platform-independent anyways.

```console
cc -o nobuild nobuild.c
./nobuild
./main_dynamic
./main_static
```
