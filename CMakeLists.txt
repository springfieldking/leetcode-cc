cmake_minimum_required (VERSION 3.0)
cmake_policy(VERSION 3.0)

project(Solution)

set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(helloworld_main helloworld_main.cc)
add_executable(p70_climbing-stairs p70_climbing-stairs.cc)
add_executable(p62_unique-paths p62_unique-paths.cc)
add_executable(p63_unique-paths-ii p63_unique-paths-ii.cc)
add_executable(p146_lru-cache p146_lru-cache.cc)
add_executable(p27_remove-element p27_remove-element.cc)


