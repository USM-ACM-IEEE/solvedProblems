#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	// Take in the number of inputs for the example

	int temp = 0;
	// Int to hold the input 
	int count = 0;
	// Int to count the number of inputs bellow zero

	for (int i = 0; i < n; ++i)
		// Loop for all inputs
	{
		cin >> temp;
		// Take in the input

		if (temp < 0)
		{
			++count;
			// Increment count if less than zero
		}
	}


	cout << count;
	// Output the answer

	return 0;
}