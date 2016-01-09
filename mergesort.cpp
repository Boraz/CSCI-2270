//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-4.

#include <iostream>
#include <string>

using namespace std;


template<class ItemType>

/** Merges two sorted array segments arr[first..mid] and
    arr[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays arr[first..mid] and
    arr[mid+1..last] are each sorted in increasing order.
 @post  arr[first..last] is sorted.
 @param arr  The given array.
 @param first  The index of the beginning of the first segment in arr.
 @param mid  The index of the end of the first segment in arr;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in arr.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array arr. */
void merge(ItemType* arr, unsigned int size, unsigned int first, 
	unsigned int mid, unsigned int last)
{
   ItemType* temp_arr = new ItemType[size];  	  // Temporary array
   
   cout << " merging " << first << " " << last << endl;
   // Initialize the local indices to indicate the subarrays
   int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray
   
   cout << " merging " << first1 << " " << last1 << endl;
   cout << " merging " << first2 << " " << last2 << endl;
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;            // Next available location in temp_arr
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, temp_arr[first..index-1] is in order
      if (arr[first1] <= arr[first2])
      {
         temp_arr[index] = arr[first1];
         first1++;
      }
      else
      {
         temp_arr[index] = arr[first2]; // seg fault here
         first2++;
      }  // end if
      index++;
   }  // end while
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, temp_arr[first..index-1] is in order
      temp_arr[index] = arr[first1];
      first1++;
      index++;
   }  // end while
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, temp_arr[first..index-1] is in order
      temp_arr[index] = arr[first2];
      first2++;
      index++;
   }  // end for
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
      arr[index] = temp_arr[index];
      
   delete [] temp_arr;
}  // end merge

template<class ItemType>
/** Sorts the items in an array into ascending order.
 @pre  arr[first..last] is an array.
 @post  arr[first..last] is sorted in ascending order.
 @param arr  The given array.
 @param first  The index of the first element to consider in arr.
 @param last  The index of the last element to consider in arr. */
void mergeSort(ItemType* arr, unsigned int size, unsigned int first, unsigned int last)
{
	cout << "sorting " << first << " " << last << endl;
   if (first < last)
   {
      // Sort each half
      int mid = first + (last - first) / 2; // Index of midpoint
      
      // Sort left half arr[first..mid]
      mergeSort(arr, size, first, mid);
      
      // Sort right half arr[mid+1..last]
      mergeSort(arr, size, mid + 1, last);
      
      // Merge the two halves
      merge(arr, size, first, mid, last);
   }  // end if
}  // end mergeSort

int main()
{
   string* a = new string[8];
   a[0] = "Q";
   a[1] = "X";
   a[2] = "R";
   a[3] = "K";
   a[4] = "F";
   a[5] = "B";
   a[6] = "I";
   a[7] = "M";
   mergeSort(a, 8, 0, 7);
   for (int i = 0; i < 8; i++)
      cout << a[i] << " ";
   cout << endl;
   
}  // end main

