cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(libredwg-cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_PYPROJECT "Build project for pyproject" OFF)

add_subdirectory(src)
