cmake_minimum_required(VERSION 3.28)
project(crdr C)

set(CMAKE_C_STANDARD 17)

add_executable(crdr main.c
        shapes/shapes.h
        shapes/vertex.def.h
        shapes/vertex.h
        shapes/vertex.status.h
        shapes/vertex.c
        shapes/shapes.c
        shapes/shapes.status.h
        shapes/shapes.def.h)

target_link_libraries(crdr user32)

add_compile_definitions(ENABLE_PRINT)
