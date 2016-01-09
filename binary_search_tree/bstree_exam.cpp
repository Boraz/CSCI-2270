// FILE: BSTreeBagExam.cxx
// Written by: Michael Main (main@colorado.edu), Nov 8, 2000
// Non-interactive test program for the BSTreeBag class
// with improved test for heap leaks.
//
// DESCRIPTION:
// Each function tests part of the BSTreeBag class, returning some
// number of points to indicate how much of the test was passed.
// A description and result of each test is printed to cout.
// Maximum number of points awarded by this program is determined by the
// constants POINTS[1], POINTS[2]...
//
// WHAT'S NEW:
// This new version of the test program includes an improved test for heap
// leaks by overriding the new and delete operators. Users should consider
// placing these new and delete operators into a separate cxx file, but
// I have included everything in one file for easier distribution.

#include <iostream>   // Provides cout
#include <cstring>    // Provides memcpy
#include "binary_search_tree.h"
using namespace std;

// Descriptions and points for each of the tests:
const size_t MANY_TESTS = 5;
const int POINTS[MANY_TESTS+1] = {
   100, // Total points for all tests.
    60,  // Test 1 points
    10,  // Test 2 points
    10,  // Test 3 points
    20,  // Test 4 points
    20   // Test 5 points
};
const char DESCRIPTION[MANY_TESTS+1][256] = {
    "tests for BSTreeBag class",
    "Testing insert and the constant member functions",
    "Testing the copy constructor",
    "Testing the assignment operator",
    "Testing erase and erase_one functions",
    "Testing operators + and +="
};


// **************************************************************************
// bool correct(
//   const BSTreeBag& test,
//   unsigned int n,
//   unsigned int count[ ],
//   int max
//   )
//   This function determines if the BSTreeBag (test) is "correct" according to
//   these requirements:
//   a. it has exactly n items.
//   b. For each i in the range 0...(max-1), the BSTreeBag contains count[i]
//      copies of i.
// **************************************************************************
bool correct(
    const binary_tree_node* test,
    unsigned int n,
    unsigned int count[],
    int max
    )
{
    int i;
    bool answer = true;
    if (size(test) != n)
        answer = false;
    else
        for (i = 0; answer && (i <= max); i++)
            if (count[i] != frequency((const binary_tree_node*) test, i))
                answer = false;
    cout << (answer ? "Test passed.\n" : "Test failed.\n") << endl;
    return answer;
}


// **************************************************************************
// int test1( )
//   Performs some basic tests of insert and the constant member
//   functions. Returns POINTS[1] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test1( )
{
    const unsigned int TESTSIZE = 3000;
    binary_tree_node* test = nullptr;
    unsigned int items[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    unsigned int rand_items[50];
    char test_letter = 'A';
    unsigned int i;
    int next;

    cout << test_letter++ << ". ";
    cout << "Testing size and count for an empty BSTreeBag.";
    cout << endl;
    if (!correct((const binary_tree_node*) test, 0, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Adding the number 4 to the BSTreeBag, and then testing\n";
    cout << "   size and count.";
    cout << endl;
    insert(test, 4);
    items[4]++;
    if (!correct((const binary_tree_node*) test, 1, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting the number 2 into the BSTreeBag.\n";
    cout << "   Then checking size and count.";
    cout << endl;
    insert(test, 2);
    items[2]++;
    if (!correct((const binary_tree_node*) test, 2, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting the number 1 into the BSTreeBag.\n";
    cout << "   Then checking size and count.";
    cout << endl;
    insert(test, 1);
    items[1]++;
    if (!correct((const binary_tree_node*) test, 3, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting the number 3 into the BSTreeBag.\n";
    cout << "   Then checking size and count.";
    cout << endl;
    insert(test, 3);
    items[3]++;
    if (!correct((const binary_tree_node*) test, 4, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting another 2 into the BSTreeBag.\n";
    cout << "   Then checking size and count.";
    cout << endl;
    insert(test, 2);
    items[2]++;
    if (!correct((const binary_tree_node*) test, 5, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting the numbers 5, 6, and 7 into the BSTreeBag.\n";
    cout << "   Then checking size and count.";
    cout << endl;
    insert(test, 5);
    insert(test, 6);
    insert(test, 7);
    items[5]++;
    items[6]++;
    items[7]++;
    if (!correct((const binary_tree_node*) test, 8, items, 7)) return 0;

    cout << test_letter++ << ". ";
    cout << "Inserting " << TESTSIZE << " random items between 0 and 49\n";
    cout << "   and then checking size and count.";
    cout << endl;
    for (i = 0; i < 50; i++)
        rand_items[i] = (i < 8) ? items[i] : 0;
    for (i = 0; i < TESTSIZE; i++)
    {
        next = rand( ) % 50;
        rand_items[next]++;
        insert(test, next);
    }
    if (!correct((const binary_tree_node*) test, TESTSIZE+8, rand_items, 49)) return 0;

    return POINTS[1];
}



// **************************************************************************
// int test2( )
//   Performs some tests of the copy constructor.
//   Returns POINTS[2] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test2( )
{
    binary_tree_node* test = nullptr;
    unsigned int items[4] = { 0, 0, 0, 0 };

    cout << "A. Testing that copy constructor works okay for empty BSTreeBag...";
    cout << flush;
    binary_tree_node* copy1 = nullptr;
    copy1 = binary_search_tree_copy(test);
    if (!correct(copy1, 0, items, 3)) return 0;

    cout << "B. Testing copy constructor with 4-item BSTreeBag...";
    cout << flush;
    insert(test, 1);
    insert(test, 1);
    insert(test, 1);
    insert(test, 1);
    binary_tree_node* copy2 = binary_search_tree_copy(test);
    insert(test, 1); // Alter the original, but not the copy
    items[1] = 4; // Should be four 1's in the copy2.
    if (!correct(copy2, 4, items, 3)) return 0;

    cout << "Copy constructor seems okay." << endl;
    return POINTS[2];
}


// **************************************************************************
// int test3( )
//   Performs some tests of the assignment operator.
//   Returns POINTS[3] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test3( )
{
    binary_tree_node* test = nullptr;
    unsigned int items[4] = { 0, 0, 0, 0 };
    char *oldbytes = new char[sizeof(binary_tree_node*)];
    char *newbytes = new char[sizeof(binary_tree_node*)];
    unsigned int i;

    cout << "A. Testing that assignment operator works okay for empty BSTreeBag...";
    cout << flush;
    binary_tree_node* copy1 = nullptr;
    insert(copy1, 1);
	copy1 = binary_search_tree_copy(test);
    if (!correct(copy1, 0, items, 3)) return 0;

    cout << "B. Testing assignment operator with 4-item BSTreeBag...";
    cout << flush;
    insert(test, 1);
    insert(test, 1);
    insert(test, 1);
    insert(test, 1);
    binary_tree_node* copy2;
    copy2 = binary_search_tree_copy(test);
    insert(test, 1); // Alter the original, but not the copy
    items[1] = 4; // Should be four 1's in the copy2.
    if (!correct(copy2, 4, items, 3)) return 0;

    cout << "C. Testing assignment operator for a self-assignment...";
    cout << flush;
    memcpy(oldbytes, &test, sizeof(binary_tree_node*));
    test = test;
    memcpy(newbytes, &test, sizeof(binary_tree_node*));
    for (i=0; i < sizeof(binary_tree_node*); i++)
        if (oldbytes[i] != newbytes[i])
        {
            cout << "failed." << endl;
            return 0;
        }
    cout << "passed.\n";        

    cout << "Assignment operator seems okay." << endl;
    return POINTS[3];
}


// **************************************************************************
// int test4( )
//   Performs basic tests for the erase and erase_one functions.
//   Returns POINTS[4] if the tests are passed.
//   Otherwise returns 0.
// **************************************************************************
int test4( )
{
    binary_tree_node* test = nullptr;
    unsigned int count[16] = { 0,1,1,1,1,1,1,1,1,0,2,1,1,1,1,1};
    unsigned int cempty[16]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    cout << "Testing removal from empty BSTreeBag (should have no effect) ...";
    cout << flush;
    if (erase_one(test, 0))
    {
	cout << "Erase function incorrectly returned true." << endl;
	return 0;
    }
    if (!correct(test, 0, cempty, 15)) return 0;
        
    cout << "Inserting these: 8 6 10 1 7 10 15 3 13 2 5 11 14 4 12" << endl;
    insert(test, 8);
    insert(test, 6);
    insert(test, 10);
    insert(test, 1);
    insert(test, 7);
    insert(test, 10);
    insert(test, 15);
    insert(test, 3);
    insert(test, 13);
    insert(test, 2);
    insert(test, 5);
    insert(test, 11);
    insert(test, 14);
    insert(test, 4);
    insert(test, 12);
    
    if (!correct(test, 15, count, 15)) return 0;

    cout << "Removing 0 (which is not in BSTreeBag, so BSTreeBag should be unchanged) ...";
    cout << flush;
    if (erase_one(test, 0))
    {
	cout << "Erase function incorrectly returned true." << endl;
	return 0;
    }
    if (!correct(test, 15, count, 15)) return 0;

    cout << "Removing the 6 ..." << flush;
    if (!erase_one(test, 6))
    {
	cout << "Erase function incorrectly returned false." << endl;
	return 0;
    }
    count[6] = 0;
    if (!correct(test, 14, count, 15)) return 0;

    cout << "Removing one 10 ..." << flush;
    erase_one(test, 10);
    count[10]--;
    if (!correct(test, 13, count, 15)) return 0;

    cout << "Removing the 1 ..." << flush;
    erase_one(test, 1);
    count[1]--;
    if (!correct(test, 12, count, 15)) return 0;

    cout << "Removing the 15 ..." << flush;
    erase_one(test, 15);
    count[15]--;
    if (!correct(test, 11, count, 15)) return 0;

    cout << "Removing the 5 ..." << flush;
    erase_one(test, 5);
    count[5]--;
    if (!correct(test, 10, count, 15)) return 0;

    cout << "Removing the 11 ..." << flush;
    erase_one(test, 11);
    count[11]--;
    if (!correct(test, 9, count, 15)) return 0;

    cout << "Removing the 3 ..." << flush;
    erase_one(test, 3);
    count[3]--;
    if (!correct(test, 8, count, 15)) return 0;

    cout << "Removing the 13 ..." << flush;
    erase_one(test, 13);
    count[13]--;
    if (!correct(test, 7, count, 15)) return 0;

    cout << "Removing the 2 ..." << flush;
    erase_one(test, 2);
    count[2]--;
    if (!correct(test, 6, count, 15)) return 0;

    cout << "Removing the 14 ..." << flush;
    erase_one(test, 14);
    count[14]--;
    if (!correct(test, 5, count, 15)) return 0;

    cout << "Removing the 4 ..." << flush;
    erase_one(test, 4);
    count[4]--;
    if (!correct(test, 4, count, 15)) return 0;

    cout << "Removing the 12 ..." << flush;
    erase_one(test, 12);
    count[12]--;
    if (!correct(test, 3, count, 15)) return 0;

    cout << "Removing the 8 ..." << flush;
    erase_one(test, 8);
    count[8]--;
    if (!correct(test, 2, count, 15)) return 0;

    cout << "Removing the 7 ..." << flush;
    erase_one(test, 7);
    count[7]--;
    if (!correct(test, 1, count, 15)) return 0;

    cout << "Inserting more 10's ..." << flush;
    insert(test, 10);
    insert(test, 10);
    insert(test, 10);

    cout << "Removing all 10's ..." << flush;
    erase(test, 10);
    count[10] = 0;
    if (!correct(test, 0, count, 15)) return 0;
    
    cout << "Erase and erase_one functions passed my tests." << endl;
    return POINTS[4];
}

int test5( )
{
    binary_tree_node* test1 = nullptr;
	insert(test1, 98);
	insert(test1, 7);
	insert(test1, 99);
	insert(test1, 3);
	insert(test1, 7);
	
    binary_tree_node* test2 = nullptr;
	insert(test2, 14);
	insert(test2, 20);
	insert(test2, 6);
	insert(test2, 19);
	insert(test2, 5);
	
	binary_tree_node* test3 = nullptr;
	test3 = add(test1, test2);
	
	unsigned int arr[100];
	for (unsigned int k = 0; k < 100; ++k)
		arr[k] = frequency(test3, k);
	if (arr[98] + arr[97] + arr[99] + arr[3] + arr[7] + arr[14] + arr[20] + arr[6] + arr[19] + arr[5] != size(test3))	
		cout << "operator + failed" << endl;
	combine(test2, (const binary_tree_node*) test1);
	for (unsigned int k = 0; k < 100; ++k)
		arr[k] = frequency(test2, k);
	if (arr[98] + arr[97] + arr[99] + arr[3] + arr[7] + arr[14] + arr[20] + arr[6] + arr[19] + arr[5] != size(test2))	
		cout << "operator += failed" << endl;
	combine(test1, (const binary_tree_node*) test1);
	for (unsigned int k = 0; k < 100; ++k)
		arr[k] = frequency(test1, k);
	if (arr[98] != 2 || arr[97] != 2 || arr[99] != 2 || arr[3] != 2 || arr[7] != 2)	
		cout << "operator += failed self assignment check" << endl;
	
    cout << "+ and += seem okay." << endl;
    return POINTS[5];
}


int run_a_test(int number, const char message[], int test_function( ), int max)
{
    int result;
    
    cout << endl << "START OF TEST " << number << ":" << endl;
    cout << message << " (" << max << " points)." << endl;
    result = test_function( );
    if (result > 0)
    {
        cout << "Test " << number << " got " << result << " points";
        cout << " out of a possible " << max << "." << endl;
    }
    else
        cout << "Test " << number << " failed." << endl;
    cout << "END OF TEST " << number << "." << endl << endl;
    
    return result;
}


// **************************************************************************
// int main( )
//   The main program calls all tests and prints the sum of all points
//   earned from the tests.
// **************************************************************************
int main( )
{
    int sum = 0;

    sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
    sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);
    sum += run_a_test(3, DESCRIPTION[3], test3, POINTS[3]);
    sum += run_a_test(4, DESCRIPTION[4], test4, POINTS[4]);
    sum += run_a_test(5, DESCRIPTION[5], test5, POINTS[5]);

    cout << "If you submit this List to Dora now, you will have\n";
    cout << sum << " points out of the ";
    cout << POINTS[0];
    cout << " points from this test program.\n";
    
    return EXIT_SUCCESS;

}
