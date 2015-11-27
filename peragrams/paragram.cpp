#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string input;
	cin >> input;
	// Take in the test case

	map<char, bool> letters;
	// This will track the balence of the letters

	for (unsigned int s = 0; s < input.size(); ++s)
		// Loop for each letter
	{
		if (letters.find(input[s]) == letters.end())
			// If there has not been an occurence of this letter then add it
		{
			letters.insert(pair<char, bool>(input[s], false));
			// It is false because 1 is unbalenced
		}
		else
		{
			if (letters[input[s]])
			{
				letters[input[s]] = false;
			}
			else
			{
				letters[input[s]] = true;
			}
			// Flip the bool of that letter
		}
	}

	int toatal_unbalenced = 0;
	// Tracks the number of letters unbalenced

	for (map<char, bool>::iterator it = letters.begin(); it != letters.end(); ++it)
	{
		if (!it->second)
		{
			++toatal_unbalenced;
		}
	}

	if (toatal_unbalenced == 0)
		// Exeption case to the bellow equation
	{
		cout << 0;
		return 0;
		// Exit to avoid printing twice
	}


	cout << toatal_unbalenced - ((input.size() - (toatal_unbalenced - 1)) % 2);
	// Output the number that need to be removed keeping in mind
	//	that an odd length will always have one off balence and that the 
	//	size will change as you remove them (toatal_unbalenced - 1) this accounts for that

	return 0;
}