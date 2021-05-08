run: ./liscc
	./liscc

build: CMakeLists.txt lis.cc lis.h main.cc
	g++ -o liscc lis.cc main.cc

./liscc: CMakeLists.txt lis.cc lis.h main.cc
	g++ -o liscc lis.cc main.cc

test: ./build/lis_test
	./build/lis_test

./build/lis_test: CMakeLists.txt lis.cc lis.h lis_test.cc main.cc
	mkdir -p build && cmake -S . -B ./build && cmake --build build

lint:
	cpplint *.cc *.h
