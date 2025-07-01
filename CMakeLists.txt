cmake_minimum_required(VERSION 3.15)
project(Option-Pricing VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library
add_library(fxoptions
  src/bs.cpp
  src/mc.cpp
  src/pde.cpp
  src/quadrature.cpp
)
target_include_directories(fxoptions PUBLIC include)

# Examples
add_executable(cli_demo examples/cli_demo.cpp)
target_link_libraries(cli_demo PRIVATE fxoptions)

# Tests
enable_testing()
find_package(Catch2 REQUIRED)

add_executable(test_bs tests/test_bs.cpp)
target_link_libraries(test_bs PRIVATE fxoptions Catch2::Catch2)
add_test(NAME BS COMMAND test_bs)

# (Repeat for test_mc, test_pde, test_quadrature…)
