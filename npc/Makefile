CXX := verilator
CXXFLAGS :=  --cc --exe --build --trace-fst -j 0 -Wall

CSRC := $(wildcard csrc/*.cpp)
VSRC := $(wildcard vsrc/*.v)

TOP := top

SOURCES := $(CSRC) $(VSRC)
TARGET := obj_dir/V$(TOP)

.PHONY: all sim run
all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	$(CXX) $(CXXFLAGS) --top-module $(TOP) $(SOURCES)
run:
	$(TARGET)

include ../Makefile
