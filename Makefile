# Special thanks to https://github.com/pertusa for the Makefile
CFLAGS=-std=c++11 -Wno-unknown-pragmas -Wall

TARGET = parse_arguments
GCC=g++

SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, %.o, $(SRC))

ALL : $(TARGET)

parse_arguments : parse_arguments.o
	$(GCC) -O3  -o $@ $< 

%.o : %.cpp
	$(GCC) -O3 -o $@ -c $< $(CFLAGS)

clean: 
	rm -f $(TARGET)
	rm -f *.d *.o

