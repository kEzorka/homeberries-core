cmake_minimum_required(VERSION 3.15)
project(homeberries-core VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED COMPONENTS locale date_time)
if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost.Locale or Boost.Date_Time not found")
endif()

file(GLOB_RECURSE HB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
add_library(homeberries-core-lib STATIC ${HB_SOURCES})

target_include_directories(homeberries-core-lib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/containers>
    $<INSTALL_INTERFACE:conteiners>
)

target_link_libraries(homeberries-core-lib
  PUBLIC
    Boost::locale
    Boost::date_time
)

target_compile_options(homeberries-core-lib
  PRIVATE
    $<$<CONFIG:Debug>:-g>
)

add_executable(homeberries-core main.cpp)
target_link_libraries(homeberries-core PRIVATE homeberries-core-lib)
