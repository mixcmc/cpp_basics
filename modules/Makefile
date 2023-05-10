CXX = g++
CXXFLAGS = -O3 -pedantic-errors -std=c++20 -fmodules-ts

all: modules01

modules01: modules01.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f modules01
