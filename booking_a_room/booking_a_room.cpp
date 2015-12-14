#include <iostream>

using namespace std;

int main()
{
	int total_rooms;
	int rooms_booked;
	// Ints to hold the input


	cin >> total_rooms;
	// Take in the total number of rooms
	cin >> rooms_booked;
	// Take in the number of rooms that are booked


	if (total_rooms == rooms_booked)
	{
		cout << "too late";
		// If the hotel is booked then output too full
		return 0;
		// exit
	}


	bool *open_room = new bool[total_rooms];
	// Boolean array to find an open room

	for (int i = 0; i < total_rooms; ++i)
	{
		open_room[i] = true;
		// Mark all rooms as being open
	}


	int current = 0;
	// Temp int to hold the taken room to be checked off

	for (int taken = 0; taken < rooms_booked; ++taken)
	{
		cin >> current;
		// Take in current

		open_room[current - 1] = false;
		// Mark the room as taken
	}


	// Output
	for (int out = 0; out < total_rooms; ++out)
	{
		if (open_room[out])
		{
			cout << out + 1;
			delete[] open_room;
			return 0;
			// Output the first open room then exit
		}
	}


	delete[] open_room;
	return 0;
}