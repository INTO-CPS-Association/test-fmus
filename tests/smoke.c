#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

int main(int argc, char **argv) {
    if (argc != 3) return 1;
#ifdef _WIN32
    HMODULE library = LoadLibraryA(argv[1]);
    if (!library) {
        fprintf(stderr, "Cannot load %s: %lu\n", argv[1], GetLastError());
        return 1;
    }
    const char *(*get_version)(void) = (const char *(*)(void))GetProcAddress(library,
            strcmp(argv[2], "2") == 0 ? "fmi2GetVersion" : "fmi3GetVersion");
#else
    void *library = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!library) {
        fprintf(stderr, "Cannot load %s: %s\n", argv[1], dlerror());
        return 1;
    }
    const char *(*get_version)(void) = (const char *(*)(void))dlsym(library,
            strcmp(argv[2], "2") == 0 ? "fmi2GetVersion" : "fmi3GetVersion");
#endif
    if (!get_version || !get_version() || get_version()[0] != argv[2][0]) {
        fprintf(stderr, "Missing or invalid FMI version in %s\n", argv[1]);
        return 1;
    }
#ifdef _WIN32
    FreeLibrary(library);
#else
    dlclose(library);
#endif
    return 0;
}