#
# PROGRAM:   assign6
# AUTHOR:    name
# LOGON ID:  z-ID
# DUE DATE:  10/13/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o matrix.o
	$(CXX) $(CCFLAGS) -o assign6 $^

# Rules to compile source code files to object code
assign6.o: assign6.cpp matrix.h
matrix.o: matrix.cpp matrix.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign6 *.o
