cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER "/usr/bin/clang-15")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-15")

project(cc-splitter)
include_directories(PUBLIC /usr/lib/llvm-15/include/)
add_executable(cc-splitter splitter.cc ast.cc)
target_link_libraries(cc-splitter PUBLIC clang-cpp15 LLVM-15)
