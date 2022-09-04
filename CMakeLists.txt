cmake_minimum_required(VERSION 3.10)
project(TinyRenderer)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定为C++14 版本
set(CMAKE_CXX_STANDARD 17)

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