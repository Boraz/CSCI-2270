#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arr;
	int num;
	
	init(arr);
	
	for (unsigned int i = 0; i < 4; ++i)
	{
		cout << "Enter a number to add: ";
		cin >> num;
		add(arr, num);
		print(arr);
	}
	
	for (unsigned int i = 0; i < 4; ++i)
	{
		cout << "Enter a number to remove: ";
		cin >> num;
		//remove(arr, num);
		if(remove(arr,num)==false)
		{
			print(arr);
			cout << "Enter a number to remove: ";
			cin >> num;
			remove(arr, num);
		}
		print(arr);
	}
	cout << "Finished";
	destr(arr);
}
