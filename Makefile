CXX = g++
CXXFLAGS = -O3 -pedantic-errors -std=c++20

SRCDIR := .
SUBDIRS := $(wildcard */.)
EXCLUDE_DIRS := modules
SUBDIRS := $(filter-out $(addsuffix /.,$(EXCLUDE_DIRS)), $(SUBDIRS))

BINARIES := $(patsubst %.cpp,%,$(wildcard $(SRCDIR)/*.cpp))


all: $(BINARIES)
	$(foreach subdir,$(SUBDIRS), $(MAKE) -C $(subdir);)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


.SILENT: run
.PHONY: run
run: $(BINARIES)
	$(foreach program,$^,echo "=== $(program) ===";./$(program);)

clean:
	rm -f $(BINARIES)
	$(foreach subdir,$(SUBDIRS), $(MAKE) -C $(subdir) clean;)
