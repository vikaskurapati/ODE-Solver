cmake_minimum_required(VERSION 3.0)
project(ode-solver VERSION 1.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(main main.cpp expliciteuler.cpp impliciteuler.cpp solver.cpp)

add_executable(solver-test test.cpp expliciteuler.cpp impliciteuler.cpp solver.cpp)

add_test(NAME solver-test
	COMMAND solver-test)

set (CMAKE_CXX_FLAGS "-O3")	