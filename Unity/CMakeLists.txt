cmake_minimum_required(VERSION 3.15)

project(the-algorithm-design-manual)

add_subdirectory(sorting)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()

target_include_directories(Main PUBLIC
    "${PROJECT_SOURCE_DIR}/Unity-2.5.2"
)
