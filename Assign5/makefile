#
# PROGRAM:    Assignment 5
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
assign5: main.o book.o book_store.o
	$(CXX) $(CXXFLAGS) -o assign5 $^

# Rules to compile source code file to object code
main.o: main.cpp book_store.h
book.o: book.cpp book.h
book_store.o: book_store.cpp book_store.h

book_store.h: book.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f assign5 *.o
