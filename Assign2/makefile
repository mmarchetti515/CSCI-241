
# PROGRAM:    Assignment 2
# PROGRAMMER: Michael Marchetti
# LOGON ID:   z1860574
# DATE DUE:   9/9/2021
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file       
all: hanoi queens

hanoi: hanoi.o
        $(CXX) $(CXXFLAGS) -o hanoi $^

queens: queens.o
        $(CXX) $(CXXFLAGS) -o queens $^

# Rules to compile source code files to object code
hanoi.o: hanoi.cpp
queens.o: queens.cpp

# Pseudo-target to remove object code and executable files       
clean:
        rm -f hanoi queens *.o
