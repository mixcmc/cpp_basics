CXX = g++
CXX_MOD = g++ -c -x c++-system-header
CXXFLAGS = -O3 -pedantic-errors -std=c++20 -fmodules-ts
SYS_HDRS := iostream

.PHONY: all clean sys_modules run
.SILENT: run

all: sys_modules modules01

sys_modules:
	$(CXX_MOD) $(CXXFLAGS) $(SYS_HDRS)

modules01: modules01.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

run:
	echo "== modules01 =="
	./modules01

clean:
	rm -f modules01
