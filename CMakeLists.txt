cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

project(SimpleCppBenchmark)

set(MAIN main.cpp)
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HED "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_executable(${PROJECT_NAME} ${MAIN} ${SRC} ${HED})
