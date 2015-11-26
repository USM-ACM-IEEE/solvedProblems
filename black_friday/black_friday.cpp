#include <iostream>
#include <map>
using namespace std;

int main()
{
	int size;
	cin >> size;
	// Grabs the size of the testing case

	int *rolls = new int[size];
	// This is the array to hold the dice rolls

	for (int i = 0; i < size; ++i)
	{
		cin >> rolls[i];
		// Take in the rolls for each person
	}


	map<int, bool> occ;
	// A map to track the occurences of each numbers

	for (int s = 0; s < size; ++s)
	{
		if (occ.find(rolls[s]) == occ.end())
			// If not found
		{
			occ.insert(pair<int, bool>(rolls[s], true));
			// Insert the new number in the map which is true because it's the only one
		}
		else
		{
			occ[rolls[s]] = false;
			// The found number has occured more than once
		}
	}

	int max_value = 0;
	// Stores the max that doesn't repeat

	for (map<int, bool>::iterator it = occ.begin(); it != occ.end(); ++it)
	{
		if (it->second)
			// If the value occured once
		{
			max_value = it->first;
			// Saves the greater value since maps are sorted we know this value is larger
		}
	}


	if (max_value == 0)
		// There is no winner because all values repeat
	{
		cout << "none";
		return 0;
	}


	for (int f = 0; f < size; ++f)
	{
		if (max_value == rolls[f])
			// If this is the index of the winner cout the position and end
		{
			cout << f + 1;
			return 0;
		}
	}

	return 0;
}