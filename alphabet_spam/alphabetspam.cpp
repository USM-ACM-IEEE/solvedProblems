#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string input;
	cin >> input;
	// Holds the string to be parsed

	double spaces = 0, lower_letters = 0, upper_letters = 0, symbols = 0;

	for (int l = 0; l < input.size(); ++l)
	{
		if (input[l] == '_')
		{
			++spaces;
			// Increment the counter to count the spaces
		}
		else if (islower(input[l]))
		{
			++lower_letters;
			// Increment the counter to count the lower
		}
		else if (isupper(input[l]))
		{
			++upper_letters;
			// Increment the counter to count the upper letters
		}
		else
		{
			++symbols;
			// Increment the counter to count the symbols
		}
	}

	cout << fixed << showpoint << setprecision(10);
	cout << spaces / input.size() << endl;
	cout << lower_letters / input.size() << endl;
	cout << upper_letters / input.size() << endl;
	cout << symbols / input.size() << endl;


	return 0;
}