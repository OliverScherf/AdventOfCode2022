cmake_minimum_required(VERSION 3.16)
project(adventofcode2022)

set(CXX_STANDARD CXX_20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

include(CompilerWarnings)
include(Sanitizers)
include(StaticAnalyzers)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(day01_calorie_counting src/day01_calorie_counting.cpp)
target_compile_definitions(day01_calorie_counting PRIVATE INPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/src/day01_input.txt\")

add_executable(day02_rock_paper_scissors src/day02_rock_paper_scissors.cpp)
target_compile_definitions(day02_rock_paper_scissors PRIVATE INPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/src/day02_input.txt\")

add_executable(day03_rucksack src/day03_rucksack.cpp)
target_compile_definitions(day03_rucksack PRIVATE INPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/src/day03_input.txt\")

add_executable(day04_camp_cleaning src/day04_camp_cleaning.cpp)
target_compile_definitions(day04_camp_cleaning PRIVATE INPUT_FILE_PATH=\"${CMAKE_SOURCE_DIR}/src/day04_input.txt\")

add_executable(day05_crates src/day05_crates.cpp)
target_compile_definitions(day05_crates
  PRIVATE
    INPUT_FILE_PATH_MOVES=\"${CMAKE_SOURCE_DIR}/src/day05_input_moves.txt\"
    INPUT_FILE_PATH_CRATES=\"${CMAKE_SOURCE_DIR}/src/day05_input_stacks.txt\"
)
