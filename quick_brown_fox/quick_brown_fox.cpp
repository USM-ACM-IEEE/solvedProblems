#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	bool letters[26];
	// Array to track what is in the string

	int test_cases;
	cin >> test_cases;
	// Take in the number of test cases to loop

	char input_char;
	// To pause the input
	string input;
	// String to hold the input of each test case
	bool is_first;

	for (int test = 0; test < test_cases; ++test)
		// Loop for all the test cases
	{
		for (int s = 0; s < 26; ++s)
		{
			letters[s] = false;
			// Initailize the array to false
		}

		cin >> input_char;
		getline(cin, input);
		input = input_char + input;
		// Take in the test case

		for (unsigned int l = 0; l < input.size(); ++l)
		{
			if (isalpha(input[l]))
			{
				letters[static_cast<int>(tolower(input[l])) - 97] = true;
				// If the current spot in the input is a letter check it off the list
			}
		}

		is_first = true;
		// Variable to track if the heading needs to be output

		for (int a = 0; a < 26; ++a)
		{
			if (!letters[a])
			{
				if (is_first)
					// Output that it is not a pangram
				{
					cout << "missing ";
					is_first = false;
				}

				cout << static_cast<char>(a + 97);
				// Output each missing letter
			}
		}

		if (is_first)
			// If nothing has been output then it is a pangram
		{
			cout << "pangram" << endl;
		}
		else
		{
			cout << endl;
			// Finish the output of the missing case
		}
	}

	return 0;
}