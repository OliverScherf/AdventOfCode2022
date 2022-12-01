find_program(CPP_CHECK_EXECUTABLE cppcheck)
if(CPP_CHECK_EXECUTABLE)
  set(CMAKE_CXX_CPPCHECK
      ${CPP_CHECK_EXECUTABLE}
      --suppress=missingInclude
      --enable=all
      --inline-suppr
      --inconclusive)
else()
  message(WARNING "cppcheck not found")
endif()

find_program(CLANGTIDY_EXECUTABLE clang-tidy)
if(CLANGTIDY_EXECUTABLE)
  set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY_EXECUTABLE} -extra-arg=-Wno-unknown-warning-option -extra-arg=-std=c++20)
else()
  message(WARNING "clang-tidy not found")
endif()
