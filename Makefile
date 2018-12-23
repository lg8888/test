OPT=0
STD=c++17

CXX_FLAGS =-g -std=$(STD)

SRC_FILES=$(wildcard *.cpp)
X_FILES = $(SRC_FILES:.cpp=.x)
S_FILES = $(SRC_FILES:.cpp=.s)

all: $(X_FILES) $(S_FILES)

%.x: %.cpp
	g++ $(CXX_FLAGS) -O2 -o $@ $<


%.s: %.cpp
	g++ $(CXX_FLAGS) -O0 -o $@ $<