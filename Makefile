run: ./liscpp
	./liscpp

build: CMakeLists.txt lis.cc lis.h main.cc
	g++ -o liscpp lis.cc main.cc

./liscpp: CMakeLists.txt lis.cc lis.h main.cc
	g++ -o liscpp lis.cc main.cc

test: ./build/lis_test
	./build/lis_test

./build/lis_test: CMakeLists.txt lis.cc lis.h lis_test.cc main.cc
	mkdir -p build && cmake -S . -B ./build && cmake --build build
