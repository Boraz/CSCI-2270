# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_big_number.o test_big_number doubly_linked_list.o big_number.o

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your queue and singly_linked_list class together
test_big_number: test_big_number.o doubly_linked_list.o big_number.o
	g++ -std=c++0x -Wall -g test_big_number.o doubly_linked_list.o big_number.o -o test_big_number 

doubly_linked_list.o: doubly_linked_list.h doubly_linked_list.cpp
	g++ -std=c++0x -Wall -g -c doubly_linked_list.cpp -o doubly_linked_list.o

big_number.o: big_number.h big_number.cpp
	g++ -std=c++0x -Wall -g -c big_number.cpp -o big_number.o

test_big_number.o: doubly_linked_list.h test_big_number.cpp big_number.h
	g++ -std=c++0x -Wall -g -c test_big_number.cpp -o test_big_number.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
