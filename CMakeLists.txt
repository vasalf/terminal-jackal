cmake_minimum_required(VERSION 3.10)
project(jackal)

set(CMAKE_CXX_STANDARD 17)
include_directories("${CMAKE_SOURCE_DIR}/lib")

add_library(ljackal STATIC
    lib/jackal.cpp
)

add_executable(jackal main.cpp)
target_link_libraries(jackal ljackal)
