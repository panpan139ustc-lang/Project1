BIN=hello 
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

#定义编译选项
CXXFLAGS=-std=c++11 -Wall
CC=g++
Echo=echo 
RM=rm -rf

$(BIN):$(OBJ)
	@$(CC) $(CXXFLAGS) -o $@ $^
	@$(Echo) "linking $^ to $@ ...done"

$%.o:%.cpp 
	@$(CC) $(CXXFLAGS) -c $<
	@$(Echo) "compling $< to $@ ...done"


.PHONY:clean
clean:
	@$(Echo) "BEGIN CLEANNING"
	@$(RM) $(BIN) $(OBJ)
	@$(Echo) "END CLEANNING"


