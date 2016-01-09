#include "dynamic_size_array_sorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
	arr.count = 0;
	
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
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

void clear(int_array& arr)
{
	arr.count = 0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
		cout << endl;
}

void sort(int_array& arr)
{
	for(unsigned int v =0; v < arr.count; ++v)
	{
		for(unsigned int k = 1; k < arr.count; ++k)
		{
			while(arr.data[k] < arr.data[k-1])
			{
				swap(arr.data[k], arr.data[k-1]);
			}
		}
	}
}

void swap(int& t1, int& t2)
{
	int t3;
	t3 = t1;
	t1 = t2;
	t2 = t3;
}

void add(int_array& arr, const int& payload)
{
		arr.data[arr.count]=payload;
		arr.count++;
		sort(arr);

	if(arr.count > arr.capacity) //array is full, call the resize function to resize the array
	{
		resize(arr); //call the resize function
	}
}

bool remove(int_array& arr, const int& target)
{
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
		}
	}
	
	return true;
}

bool contains(const int_array& arr, const int& target)
{
	for(unsigned int i = 0; i < arr.count; ++i)
	{
		if(arr.data[i] == target)
		{
			cout << "Yes contains # " << target << endl;
			break;
		}
		else if(arr.data[i] != target && i >= arr.count - 1)
		{
			cout << "Does not contain # " << target << endl;
		}
	}
	return 0;
}



