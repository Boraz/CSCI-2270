//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-1.

#include <iostream>
#include <string>

using namespace std;

/** Finds the largest item in an array.
 @pre  The size of the array is >= 1.
 @post  The arguments are unchanged.
 @param theArray  The given array.
 @param size  The number of elements in theArray.
 @return  The index of the largest entry in the array. */

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  The array is sorted into ascending order; the size of the array
    is unchanged.
 @param theArray  The array to sort.
 @param n  The size of theArray. */

template <class ItemType>
int findIndexofLargest(const ItemType* theArray, unsigned int size)
{
   int indexSoFar = 0; // Index of largest entry found so far
   for (int currentIndex = 1; currentIndex < size; currentIndex++)
   {
      // At this point, theArray[indexSoFar] >= all entries in
      // theArray[0..currentIndex - 1]
      if (theArray[currentIndex] > theArray[indexSoFar])
         indexSoFar = currentIndex;
   }  // end for
   return indexSoFar; // Index of largest entry
}  // end findIndexofLargest

template <class ItemType>
void selectionSort(ItemType* theArray, unsigned int n)
{
   // last = index of the last item in the subarray of items yet
   //        to be sorted;
   // largest = index of the largest item found
   for (int last = n - 1; last >= 1; last--)
   {
      // At this point, theArray[last+1..n-1] is sorted, and its 
      // entries are greater than those in theArray[0..last].
      // Select the largest entry in theArray[0..last]
      int largest = findIndexofLargest(theArray, last+1);
      
      // Swap the largest entry, theArray[largest], with
      // theArray[last]
      std::swap(theArray[largest], theArray[last]);
      
      cout << "Pass " << n-1 - last << " gives: " << endl;
      for (int i = 0; i < n; i++)
		cout << theArray[i] << " ";
	  cout << endl;

   }  // end for
}  // end selectionSort

int main()
{
   string a[11] = {"6", "3", "9", "8", "8", "3", "1", "7", "3", "9", "1"};
   selectionSort(a, 11);
   cout << "After sorting " << endl;
   for (int i = 0; i < 11; i++)
      cout << a[i] << " ";
   cout << endl;   
}  // end main

