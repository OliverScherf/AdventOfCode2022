cmake_minimum_required(VERSION 3.16)
project(adventofcode2022)

set(CXX_STANDARD CXX_20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

include(CompilerWarnings)
include(Sanitizers)
include(StaticAnalyzers)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(day01_calorie_counting
  src/day01_calorie_counting.cpp
)

target_compile_definitions(day01_calorie_counting
  PRIVATE  
    INPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/src/day01_input.txt\"
)
