#
# PROGRAM: shape
#

# compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
assign12: assign12.o shape.o circle.o rectangle.o triangle.o
	$(CXX) $(CXXFLAGS) -o assign12 $^

# Rules to compile source code file to object code
assign12.o: assign12.cpp shape.cpp circle.h rectangle.h triangle.h
shape.o: shape.h shape.cpp
circle.o: circle.h circle.cpp
rectangle.o: rectangle.h rectangle.cpp
triangle.o: triangle.h triangle.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 *.o 