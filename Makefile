hello-debug:hello.cpp
	g++ -std=c++11 -o $@ $^ -g
.PHONY:clean
clean:
	rm -rf hello-debug


















#BIN=hello 
#SRC=$(wildcard *.cpp)
#OBJ=$(SRC:.cpp=.o)
#
##定义编译选项
#CXXFLAGS=-std=c++11 -Wall
#CC=g++
#Echo=echo 
#RM=rm -rf
#
#$(BIN):$(OBJ)
#	@$(CC) $(CXXFLAGS) -o $@ $^ -g
#	@$(Echo) "linking $^ to $@ ...done"
#
#$%.o:%.cpp 
#	@$(CC) $(CXXFLAGS) -c $< -g
#	@$(Echo) "compling $< to $@ ...done"
#
#
#.PHONY:clean
#clean:
#	@$(Echo) "BEGIN CLEANNING"
#	@$(RM) $(BIN) $(OBJ)
#	@$(Echo) "END CLEANNING"


