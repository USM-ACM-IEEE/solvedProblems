#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int test_cases;
	cin >> test_cases;
	// Int to hold the number of test cases

	string encoded_message;
	char **cypher = nullptr;
	// 2-D dynamic array will be used to hold the message while being decoded
	// The string will hold the original message
	
	int length = 0, spot = 0;
	for (int test = 0; test < test_cases; ++test)
	{
		cin >> encoded_message;
		length = sqrt(encoded_message.size());
		if (length*length != encoded_message.size())
			++length;
		// Takes in the encoded message and determines the size of square needed


		cypher = new char*[length];
		for (int l = 0; l < length; ++l)
		{
			cypher[l] = new char[length];
		}
		// Constructs the square to decode the message

		
		for (int row = 0; row < length; ++row)
		{
			for (int col = 0; col < length; ++col)
			{
				if (spot == encoded_message.size() - 1 && length*length != encoded_message.size())
				{
					cypher[row][col] = '*';
					continue;
				}
				cypher[row][col] = encoded_message[spot];
				++spot;
			}
		}
		// Puts the message into the cypher


		for (int col_out = length - 1; col_out >= 0; --col_out)
		{
			for (int row_out = 0; row_out < length; ++row_out)
			{
				if ( cypher[row_out][col_out] == '*')
				{
					continue;
				}
				cout << cypher[row_out][col_out];
			}
		}
		cout << endl;
		// Output the decoded message


		for (int d = 0; d < length; ++d)
		{
			delete[] cypher[d];
		}
		delete[] cypher;
		spot = 0;
	}

	return 0;
}