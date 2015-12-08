#include <iostream>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n = 0;
	// Holds the length of the list

	array<int, 5000> first_list;
	array<int, 5000> second_list;
	// These will hold each test cases list

	map<int, int> matching_list;
	// This will hold the final corrected lists

	cin >> n;
	// Take in the legnth of the lists

	map<int, int>::iterator current = matching_list.begin();
	// An iterator to traverse the map


	while (n != 0)
		// Loop for all test cases
	{
		for (int input = 0; input < n; ++input)
		{
			cin >> first_list[input];
			// Take in the first list
			matching_list.insert(pair<int, int>(first_list[input], 0));
			// Add the value to the final list since the first list is correct
		}

		for (int input2 = 0; input2 < n; ++input2)
		{
			cin >> second_list[input2];
			// Take in the second list
		}

		sort(second_list.begin(), second_list.begin() + n);
		// Sort the second list

		current = matching_list.begin();
		// Move the iterator the the front of the list

		for (array<int, 5000>::iterator it = second_list.begin(); it != second_list.begin() + n; ++it)
			// Fix the final list
		{
			current->second = *it;
			// Change the second value to the proper number

			++current;
			// Move the map iterator forward
		}


		// Output
		for (int out = 0; out < n; ++out)
		{
			cout << matching_list[first_list[out]] << endl;
			// Output the final list based on the first list
		}

		cin >> n;
		matching_list.clear();
		// Delete the old list in the map and take in the new n
	}

	return 0;
}