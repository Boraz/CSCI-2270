//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-3.

#include <iostream>
#include <string>

using namespace std;
template<class ItemType>

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
void insertionSort(ItemType* theArray, unsigned int n)
{
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region.
   // Initially, sorted region is theArray[0],
   // unsorted region is theArray[1..n-1].
   // In general, sorted region is theArray[0..unsorted-1],
   // unsorted region theArray[unsorted..n-1]
   for (unsigned int unsorted = 1; unsorted < n; unsorted++)
   {
      // At this point, theArray[0..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[0..unsorted]
      // for theArray[unsorted], which is the first entry in the
      // unsorted region; shift, if necessary, to make room
      ItemType nextItem = theArray[unsorted];
      int loc = unsorted;
      while ((loc > 0) && (theArray[loc - 1] > nextItem))
      {
         // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         loc--;
      }  // end while
      
      // At this point, theArray[loc] is where nextItem belongs
      theArray[loc] = nextItem; // Insert nextItem into sorted region

      cout << "Pass " << unsorted - 1 << " gives: " << endl;
      for (int i = 0; i < n; i++)
		cout << theArray[i] << " ";
	  cout << endl;

   }  // end for
}  // end insertionSort

int main()
{
   string a[11] = {"6", "3", "9", "8", "8", "3", "1", "7", "3", "9", "1"};
   insertionSort(a, 11);
   cout << "After sorting " << endl;
   for (int i = 0; i < 11; i++)
      cout << a[i] << " ";
   cout << endl;
}  // end main

