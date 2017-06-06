# Special thanks to https://github.com/pertusa for the Makefile
CFLAGS=-std=c++11 -Wno-unknown-pragmas -Wall

TARGET = main
GCC=g++

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))

ALL: $(TARGET)
	@echo $(TARGET)
	@echo $(SRC)
	@echo $(OBJ)

$(TARGET) : $(OBJ)
	$(GCC) -O3  -o $@ $(OBJ)

%.o : %.cpp
	$(GCC) -O3 -o $@ -c $< $(CFLAGS)

clean: 
	rm -f $(TARGET)
	rm -f *.d *.o

