// clang++ -c l.cpp
// llvm-ar -rcs l.obj l.o
// clang++ t.cpp l.obj

#include <iostream>

#include "l.hpp"

int main() {
    std::cout << f() << std::endl;
    return 0;
}
