cmake_minimum_required(VERSION 3.10)
project(TinyRenderer)

set(HEADERS
    src/Core/DrawLine.h
    src/Core/tgaimage.h
    src/Core/Geometry.h
    src/Core/Model.h

)

set(SOURCES
    src/Core/tgaimage.cpp
    src/Core/Model.cpp
    src/main.cpp
)


set(TARGET TinyRenderer)

add_executable(${TARGET} ${HEADERS} ${SOURCES}) 