// FILE: BSTreeBagTest.cxx
// Written by Michael Main (main@colorado.edu) - Nov 8, 2000
// An interactive test program for the new BSTreeBag class, implemented with
// a binary search tree.

#include <cctype>     // Provides toupper
#include <iostream>   // Provides cout, cin
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include "binary_search_tree.h"     // Provides the binary_tree_node* class (with Item as a double)
using namespace std;


// PROTOTYPES for the functions used in this test program.
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// A line of input (with at least one character) has been read, and the first
// character of the input line is returned.

void display_binary_search_trees(const binary_tree_node* b1, const binary_tree_node* b2);
// Postcondition: The function has tested whether the numbers 0..9 are in
// the two BSTreeBags, and printed the results to standard output.

binary_tree_node* copy_binary_search_tree(binary_tree_node* b);
// Postcondition: The return value is a copy of b.

double get_number( );
// Postcondition: The user has been prompted to enter a double number. The
// number has been read, echoed to the screen, and returned by the function.

int main( )
{
    binary_tree_node *b1, *b2;  // Bags that we'll perform tests on
    b1 = nullptr; b2 = nullptr;
    
    char choice; // A command character entered by the user

    cout << "I have initialized two empty BSTreeBags of doubles." << endl;

    do
    {
		double number;
        print_menu( );
        choice = get_user_command( );
        switch (choice)
        {
            case 'C': b1 = copy_binary_search_tree(b2);
                      break;
            case 'c': b2 = copy_binary_search_tree(b1);
                      break;
            case 'S':
            case 's': cout << "The tree sizes are " << size(b1);
                      cout << " and " << size(b2) << endl;
                      break;
            case 'I': number = get_number();
					  insert(b1, number);
                      break;
            case 'i': number = get_number();
					  insert(b2, number);
                      break;
            case 'O': number = get_number();
					  erase_one(b1, number);
                      break;
            case 'o': number = get_number();
					  erase_one(b2, number);
                      break;
            case 'E': number = get_number();
					  erase(b1, number);
                      break;
            case 'e': number = get_number();
					  erase(b2, number);
                      break;
            case 'D':
            case 'd': display_binary_search_trees((const binary_tree_node*) b1, 
				(const binary_tree_node*) b2);
                      break;
	    case 'q':
	    case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default: cout << choice << " is invalid. Sorry." << endl;
        }
    }
    while ((toupper(choice) != 'Q'));

    return EXIT_SUCCESS;

}

void print_menu( )
// Library facilties used: iostream.h
{
    cout << "The following choices are available with 2 BSTreeBags: " << endl;
    cout << " C  Use the copy command to make b1 equal to b2" << endl;
    cout << " c  Use the copy command to make b2 equal to b1" << endl;
    cout << " I  Insert an item into b1" << endl;
    cout << " i  Insert an item into b2" << endl;
    cout << " E  Erase item from b1" << endl;
    cout << " e  Erase item from b2" << endl;
    cout << " O  Erase one item from b1" << endl;
    cout << " o  Erase one item from b2" << endl;
    cout << " D  Display a count of items 0-9 in b1 and b2" << endl;
    cout << " S  Print the result from the size( ) functions" << endl;
    cout << " Q  Quit this test program" << endl;
}

char get_user_command( )
// Library facilties used: iostream.h
{
    char command;

    cout << "Enter choice: ";
    cin >> command; 
   
    return command;
}

void display_binary_search_trees(const binary_tree_node* b1, const binary_tree_node* b2)
// Library facilties used: iostream.h
{
    int i;

    for (i = 0; i < 10; i++)
    {
        cout << i << " in b1? " << frequency(b1, i);
        cout << "            " << i << " in b2? " << frequency(b2, i) << endl;
    }
}

binary_tree_node* copy_binary_search_tree(binary_tree_node* b)
{
    return binary_search_tree_copy((const binary_tree_node*) b);
}

double get_number( )
// Library facilties used: iostream.h
{
    double result;

    cout << "Please enter a double number for the BSTreeBag: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
