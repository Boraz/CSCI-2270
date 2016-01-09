#include <iostream>
#include <string>
using namespace std;
string input;

int main()
{
		int step;
		cout << "Please enter a word" << endl;
		cin >> input;			//no check for null or incorect input, things will break!
		cout << "Please enter a step amount" << endl;
		cin >> step;
		string str = input;

		for (int n = 0; n < input.length(); n++)
		{
			input[n] = (((input[n] - 97) + step) % 26) + 97; // "% 26) + 97" from http://www.rowanwatson.com/c-caesar-cipher/
		}												

		cout << input << endl;
		system("pause");

		return 0;
}
