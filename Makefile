CXX = g++
CXXFLAGS = -O3 -pedantic-errors -std=c++20
SOURCES = $(wildcard *.cpp)
BINARIES = $(SOURCES:.cpp=)


all: $(BINARIES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	
.PHONY: run
run: $(BINARIES)
	$(foreach program,$^,./$(program);)

clean:
	rm -f $(BINARIES)
