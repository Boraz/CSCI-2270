# Make file for HW4, CSCI2270
# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_int_array.o test_int_array dynamic_size_array_unsorted.o

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your dynamic_size_array_unsorted class together
test_int_array: test_int_array.o dynamic_size_array_unsorted.o
	g++ -std=c++0x -Wall -g test_int_array.o dynamic_size_array_unsorted.o -o test_int_array 

# this compiles your test program, which is executable
dynamic_size_array_unsorted.o: dynamic_size_array_unsorted.h dynamic_size_array_unsorted.cpp
	g++ -std=c++0x -Wall -g -c dynamic_size_array_unsorted.cpp -o dynamic_size_array_unsorted.o

# this compiles your test program, which is executable
test_int_array.o: dynamic_size_array_unsorted.h test_int_array.cpp
	g++ -std=c++0x -Wall -g -c test_int_array.cpp -o test_int_array.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
