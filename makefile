CC=g++

GTEST=/usr/local/include/gtest
GTEST_LIB=-lgtest



INCLUDE=-I/usr/include -I$(GTEST)
LIBS=-L/usr/local/lib $(GTEST_LIB) -lpthread 
OPT=0

CXX_FLAGS=-g -Wall -O$(OPT) -std=c++1z

%.x : %.cpp
	$(CC) $(CXX_FLAGS) $(INCLUDE) $(LIBS) $< -o $@ 
