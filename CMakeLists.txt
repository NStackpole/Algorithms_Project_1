project(Project1 CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(binary-integer-test
  BinaryInteger.cpp
	main.cpp
	)

set(files BinaryInteger.hpp BinaryInteger.cpp main.cpp)

add_custom_target(printout
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)