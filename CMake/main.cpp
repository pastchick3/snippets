// In `./build` (Win):
// > cmake ..
// > cmake --build . (--config Release)
// > ./debug/Main.exe
// > cmake --install . --prefix "./install" (--config Debug)
//
// In `./build` (Linux):
// > cmake .. (-DCMAKE_BUILD_TYPE=Debug)
// > cmake --build .
// > ./Main
// > cmake --install . --prefix "./install"

#include <iostream>

#include "config.h"
#include "lib.h"

int main() {
    std::cout << "Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << "." << Tutorial_VERSION_PATCH
              << std::endl;
    std::cout << "lib fn: " << f() << std::endl;
    return 0;
}
