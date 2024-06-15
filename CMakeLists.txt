cmake_minimum_required(VERSION 3.28)
project(project_r4)

set(CMAKE_CXX_STANDARD 26)

file(GLOB SOURCES src/**/*.cpp src/*.cpp)
file(GLOB HEADERS include/**/*.hpp include/*.hpp)

add_executable(project_r4 ${SOURCES} ${HEADERS})

include_directories(include)
