# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_graph.o test_graph graph.o 

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your queue and singly_linked_list class together
test_graph: test_graph.o graph.o
	g++ -std=c++0x -Wall -g test_graph.o graph.o -o test_graph

graph.o: graph.h graph.cpp vertex.h
	g++ -std=c++0x -Wall -g -c graph.cpp -o graph.o

test_graph.o: test_graph.cpp graph.h
	g++ -std=c++0x -Wall -g -c test_graph.cpp -o test_graph.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
