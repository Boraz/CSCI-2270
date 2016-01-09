#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity]; // added. wasnt included
	arr.count = 0;
}

void clear(int_array& arr) // we can just over write everything
{
	 // destr(arr); // clear not destroy
	 // init(arr); // nope
	 arr.count = 0;
}

void destr(int_array& arr)
{
	delete [] arr.data; // 
	arr.count = 0; // nothing wrong here
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
		cout << endl; // nothing wrong here
}

bool contains(const int_array& arr, const int& target) // not called
{
	unsigned int i;
	for (i = 0; i < arr.count; ++i);
	{
		if (arr.data[i] == target) return true;
		else return false;	
	}
	return 0; // would have always returned false
	
	/*
	for(unsigned int i = 0; i < arr.count; ++i)
	{
		if(arr.data[i] == target)
		{
			return true;
			break;
		}
		
		else if(arr.data[i] != target && i >= arr.count - 1)
		{
			return false;
		}
	}
	return 0;
	*/
}

void resize(int_array& arr) // looks good
{
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	arr.data = new_data;
	delete [] arr.data;
}

void add(int_array& arr, const int& payload)
{
	
	if(arr.count > arr.capacity) // removed extra brackets, changed logic >, 
		{
			resize(arr);
		}
	
	arr.data[arr.count] = payload; // removed ++ in arr.count, could fall off
	arr.count++; // added, was not moving to the next location after adding payload

}

bool remove(int_array& arr, const int& target) // yikes format
{
	//unsigned int i = 0; 
	
	if (arr.count == 0) // = vs == ? not sure, shouldn't be true
		return false;
		
	/*while (i < arr.count && arr.data[i] != target)  i++; // i++ not in the while
	
	if (i == arr.count); // > vs ==
		return false;
	arr.data[i] = arr.data[arr.count]; // changing data[i] to arr.count, all will change to the count
	
	arr.count--; // ok
	return true; // ok
	*/
	for(unsigned int n = 0; n < arr.count; ++n)
	{
		if(arr.data[n] == target)
		{
			for(unsigned int s = n; s < arr.count; s++)
			{
				arr.data[n] = arr.data[n+1];
				n++;
			}
			arr.count--;
			return true;
		}
	}
	
	return false;
}

