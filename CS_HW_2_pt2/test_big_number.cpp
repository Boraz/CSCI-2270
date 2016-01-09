#include "big_number.h"

using namespace std;

int main()
{
	int n1, n2;
	unsigned int base;
	string s;
			
	char choice;
	do
	{
		cout << "Type 'd' to test default constructor" << endl;
		cout << "Type 'i' to test int constructor" << endl;
		cout << "Type 's' to test string constructor" << endl;
		cout << "Type 'c' to test conversion constructor" << endl;
		cout << "Type 'a' to test assignment" << endl;
		cout << "Type '>' to test input operator" << endl;
		
		cout << "Type '+' to test += operator" << endl;
		cout << "Type '-' to test -= operator" << endl;
		cout << "Type '*' to test *= operator" << endl;
		cout << "Type '=' to test comparison operators" << endl;
		cout << "Type 'q' to quit" << endl;
		cin >> choice;
	
		if (toupper(choice) == 'D')
		{
			big_number a;
			cout << "Default constructor gives " << a << endl;
		}
		
		if (toupper(choice) == 'I')
		{
			cout << "Enter an integer: ";
			cin >> n1;
			big_number b(n1);
			cout << "Int constructor with " << n1 << " gives " << b << endl;
		}
		
		if (toupper(choice) == 'S')
		{
			cout << "Enter a base: ";
			cin >> base;
			cout << "Enter a string: ";
			cin >> s;
			big_number e(s, base);
			cout << "String constructor with " << s << " in base " << 
				base << " gives " << e << endl;
		}
		
		if (toupper(choice) == 'C')
		{
			big_number e("256", 10);
			big_number d(e, 16);
			cout << "Conversion constructor with " << e << " in base " << 
				10 << " gives " << d << " in base " << 16 << endl;
		}
		
		if (toupper(choice) == 'A')
		{
			big_number d;
			big_number e("256", 10);
			big_number f(56);
			cout << "d " << d << " e " << e << " f " << f << endl;
			d = e;
			e = f;
			cout << "d " << d << " e " << e << " f " << f << endl;
		}
		
		if (choice == '>')
		{
			big_number e;
			cin >> e;
			cout << "You entered " << e << endl;
		}
		
		if (choice == '+')
		{
			cout << "Enter a number: ";
			cin >> n1;
			cout << "Enter another number: ";
			cin >> n2;
			big_number f(n1);
			big_number g(n2);
			cout << f << " " << g << endl;
			f += g;
			cout << f << endl;
		}
		
		if (choice == '-')
		{
			cout << "Enter a number: ";
			cin >> n1;
			cout << "Enter another number: ";
			cin >> n2;
			big_number f(n1);
			big_number g(n2);
			cout << f << " " << g << endl;
			f -= g;
			cout << f << endl;
		}

		if (choice == '*')
		{
			cout << "Enter a number: ";
			cin >> n1;
			cout << "Enter another number: ";
			cin >> n2;
			big_number f(n1);
			big_number g(n2);
			cout << f << "*" << g << endl;
			f *= g;
			cout << f << endl;
		}

		if (choice == '=')
		{
			cout << "Enter a number: ";
			cin >> n1;
			cout << "Enter another number: ";
			cin >> n2;
			big_number f(n1);
			big_number g(n2);
			if (f == g)
				cout << f << " == " << g << endl;
			if (f != g)
				cout << f << " != " << g << endl;
			if (f < g)
				cout << f << " < " << g << endl;
			if (f <= g)
				cout << f << " <= " << g << endl;
			if (f > g)
				cout << f << " > " << g << endl;
			if (f >= g)
				cout << f << " >= " << g << endl;
		}

	} while (toupper(choice) != 'Q'); 
}
