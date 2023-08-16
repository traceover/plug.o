// plug.o - Simple example that shows how to link static and dynamic libraries with gcc
// 
// NOTES:
//     - The '-c' flag tells GCC to only generate an object file, not an executable
//     - The '-fPIC' flag tells GCC to compile position-independent code, which is necessary for
//       dynamic libraries as they will be loaded into memory in different places at runtime
//     - Since /usr/bin/ld looks for libraries in /usr/lib, the '-L' flag is necessary
//       to tell ld where to find the shared library file

#define NOBUILD_IMPLEMENTATION
#include "nobuild.h"

int main(int argc, char **argv)
{
    GO_REBUILD_URSELF(argc, argv);
    
    // Create the plugin object file from the C source code
    CMD("gcc", "-c", "-fPIC", "plug.c"); // TODO: We technically don't need to compile the static version with -fPIC
    // Create a dynamic library from the object file
    CMD("gcc", "-shared", "-o", "libplug.so", "plug.o");
    // Create executable that is linked statically with plug.o
    CMD("gcc", "plug.o", "-o", "main_static", "main.c");
    // Create executable that is linked dynamically with libplug.so
    CMD("gcc", "-L.", "-lplug", "-o", "main_dynamic", "main.c");       

    // Verify the linkage of the executables
    // Note that for the dynamic versions there is the presence of the symbol 'plug'
    CMD("ldd", "./main_static");
    CMD("ldd", "./main_dynamic");
    CMD("objdump", "--dynamic-syms", "./main_static");
    CMD("objdump", "--dynamic-syms", "./main_dynamic");

    return 0;
}