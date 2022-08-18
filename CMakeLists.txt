cmake_minimum_required(VERSION 3.10)
project(TinyRenderer)

set(HEADERS
    src/Core/tgaimage.h

)

set(SOURCES
    src/Core/tgaimage.cpp

    src/main.cpp
)


set(TARGET TinyRenderer)

add_executable(${TARGET} ${HEADERS} ${SOURCES}) 