// clang++ -D _EXPORTING --shared -o l.dll l.cpp
// clang++ t.cpp l.lib

#include <iostream>

#include "l.hpp"

int main() {
    std::cout << f() << std::endl;
    return 0;
}
