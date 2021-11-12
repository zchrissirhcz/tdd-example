cmake_minimum_required(VERSION 3.20)
project(tdd)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(arabicToRomanNumeralConveter
  ArabicToRomanNumeralConverter.hpp
  ArabicToRomanNumeralConverter.cpp
)
target_link_libraries(arabicToRomanNumeralConveter PUBLIC GTest::gtest -coverage -lgcov)
target_compile_options(arabicToRomanNumeralConveter PUBLIC -coverage -fprofile-arcs -ftest-coverage)

include("deps.cmake")

add_executable(testbed testbed.cpp)
target_link_libraries(testbed arabicToRomanNumeralConveter)
enable_testing()
gtest_add_tests(TARGET testbed)


add_custom_target(coverage
  COMMAND lcov -d ./ -c -o lcov.info
  COMMAND lcov -r lcov.info '/usr/*' -o lcov.info
  COMMAND lcov -r lcov.info '*/build/*' -o lcov.info
  COMMAND lcov --list lcov.info
  COMMAND genhtml -o coverage_report lcov.info
  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "View test coverage html report:"
  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "    cd coverage_report"
  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "    python -m http.server 7082"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

