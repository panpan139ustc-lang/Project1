BIN=process 
CC=g++
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
CXXFLAGS=-std=c++11
RM=rm -rf
Echo=echo 

$(BIN):$(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o:%.cpp 
	$(CC) $(CXXFLAGS) -c $<

.PHONY:clean
clean:
	$(Echo) "Begin Cleanning"
	$(RM) $(BIN) $(OBJ)
