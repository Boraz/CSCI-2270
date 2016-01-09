EXPENDABLES = question18.o question18 bintree.o 

all:
	@make $(EXPENDABLES)

bintree.o: bintree.cpp bintree.h
	g++ -Wall -std=c++0x -g -c bintree.cpp -o bintree.o

# this compiles your test program and your binary_search_tree classes together
question18: question18.o binary_search_tree.o bintree.o doubly_linked_list.o
	g++ -Wall -std=c++0x -g question18.o bintree.o binary_search_tree.o doubly_linked_list.o -o question18

question18.o: binary_search_tree.h binary_search_tree.o bintree.h doubly_linked_list.h question18.cpp
	g++ -Wall -std=c++0x -g -c question18.cpp -o question18.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
