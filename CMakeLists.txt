cmake_minimum_required(VERSION 3.10.0)
project(homeberries-core)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")
file(GLOB_RECURSE INCLUDES "${PROJECT_SOURCE_DIR}/include/*.h")

set(SOURCE_FILES
    main.cpp
)

add_executable(homeberries-core ${SOURCE_FILES})