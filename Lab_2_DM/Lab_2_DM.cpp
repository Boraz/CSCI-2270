#include <iostream>
using namespace std;

int main()
{
	unsigned int array_size = 0; // upper limit of numbers to check for primes
	unsigned int pk = 0; //prime number count
	unsigned int bv = 0;

	cout << "Find primes from 0 to what? "; // ask user for upper limit

	cin >> array_size; // get size from user
	
	array_size++; // add one to array_size
	
	bool pn[array_size];
	
		for(unsigned int aa = 0; aa < array_size; aa++)
		{
			pn[aa] = 1; //set the array to true
		}
	
	pn[0] = 0;
	pn[1] = 0;

		for(unsigned int av = 4; av < array_size; av += 2) //2 is prime and 4 is a power of 2 so it is false, start with even #4 then eliminate all even numbers
		{
			pn[av] = 0;
		}
	
		for(bv = 3; bv < array_size; bv += 2) //skip every even number already set as false, count += 2
		{
			for(unsigned int cv = bv*bv; cv < array_size; cv += bv * 2) // set multiples to false
			{
				pn[cv] = 0;
			}
		}
	
		for(unsigned int n = 0; n < array_size; n++)
		{
			if(pn[n] == 1) //return all primes and count them
			{
				cout << n << ", ";
				pk++;
			}
		}
	
	cout << endl << pk << " " << "prime numbers" << endl; //cout # of prime number
	return 0;
}
