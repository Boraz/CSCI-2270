#include "dynamic_size_array_unsorted.h"

using namespace std;

void init(int_array& arr)
{
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
	arr.count = 0;
	
}

void clear(int_array& arr)
{
	arr.count = 0;
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
		cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	for(unsigned int m = 0; m < arr.count; ++m)
	{
		if(arr.data[m] == target)
		{
			return true;
			break;
		}
		
		else
		{
			return false;
		}
	break;
	}
}

void resize(int_array& arr)
{
	arr.capacity *= 2; //take arr capacity and multiply by 2
	int* L_arr = new int[arr.capacity]; //update int_array's capacity to this doubled value
		for(unsigned int j=0; j < arr.count; ++j)
		{
			L_arr[j] = arr.data[j];
		}
		
		delete [] arr.data; //remove the array (and data) from memory
		arr.data = L_arr; //set 2arr to the address of arr so that the program can use the array again under arr name
}

void add(int_array& arr, const int& payload)
{
	if(arr.count >= arr.capacity); //array is full, call the resize function to resize the array
	{
		resize(arr); //call the resize function
	}

	arr.data[arr.count]=payload; //new item into slot data[count] +1;
	arr.count++;
}

bool remove(int_array& arr, const int& target)
{
	for(unsigned int n = 0; n < arr.count; ++n)
	{
		if(arr.data[n] == target)
		{
			arr.data[n] = arr.data[arr.count-1];
			arr.count--;
		}
	}
	
	return true;
}

