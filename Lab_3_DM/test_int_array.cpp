#include "dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arr;
	int num;
	
	init(arr);
	
	for (unsigned int i = 0; i < 7; ++i)
	{
		cout << "Enter a number to add: ";
		cin >> num;
		add(arr, num);
		print(arr);
	}
	
	for (unsigned int i = 0; i < 8; ++i)
	{
		cout << "Enter a number to remove: ";
		cin >> num;
		remove(arr, num);
		print(arr);
	}
	
	clear(arr);
	add(arr, 7);
	print(arr);
	
	destr(arr);
}
