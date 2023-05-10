CXX = g++
CXX_MOD = g++ -c -x c++-system-header
CXXFLAGS = -O3 -pedantic-errors -std=c++20 -fmodules-ts

.PHONY: all clean iostream

all: iostream modules01

iostream:
	$(CXX_MOD) $(CXXFLAGS) iostream

modules01: modules01.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f modules01
