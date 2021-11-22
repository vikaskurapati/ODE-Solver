CXX = g++
CXXFLAGS = -g -Wall

main: main.o solver.o
	$(CXX) -o main main.o solver.o  $(CXXFLAGS)
test: test.o solver.o
	$(CXX) -o test test.o solver.o $(CXXFLAGS)
main.o: main.cpp solver.h
	$(CXX) -c -o main.o main.cpp $(CXXFLAGS)
test.o: test.cpp solver.h
	$(CXX) -c -o test.o test.cpp $(CXXFLAGS)
solver.o: solver.cpp
	$(CXX) -c -o solver.o solver.cpp $(CXXFLAGS)
clean:
	rm -i main test main.o test.o solver.o

