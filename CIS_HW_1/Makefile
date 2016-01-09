# Make file for HW4, CSCI2270
# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_int_list.o test_int_list singly_linked_list.o

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your singly_linked_list class together
test_int_list: test_int_list.o singly_linked_list.o
	g++ -std=c++0x -Wall -g test_int_list.o singly_linked_list.o -o test_int_list 

# this compiles your test program, which is executable
singly_linked_list.o: singly_linked_list.h singly_linked_list.cpp
	g++ -std=c++0x -Wall -g -c singly_linked_list.cpp -o singly_linked_list.o

# this compiles your test program, which is executable
test_int_list.o: singly_linked_list.h test_int_list.cpp
	g++ -std=c++0x -Wall -g -c test_int_list.cpp -o test_int_list.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
