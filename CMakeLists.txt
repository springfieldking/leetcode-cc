cmake_minimum_required (VERSION 3.0)
cmake_policy(VERSION 3.0)

project(Solution)

set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(p70_climbing-stairs p70_climbing-stairs.cc)
add_executable(p62_unique-paths p62_unique-paths.cc)


