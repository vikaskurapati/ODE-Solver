cmake_minimum_required(VERSION 3.0)
project(ode-solver VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

add_executable(main main.cpp solver.cpp)

add_executable(solver-test test.cpp solver.cpp)

add_test(NAME solver-test
	COMMAND solver-test)

