cmake_minimum_required(VERSION 3.15) # for the `install` option of the `cmake` command

project(Tutorial VERSION 1.0.2)
configure_file(config.h.in config.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_executable(Main main.cpp)
target_link_libraries(Main PUBLIC Lib)
target_include_directories(Main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/lib"
                           )

install(TARGETS Main DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)
