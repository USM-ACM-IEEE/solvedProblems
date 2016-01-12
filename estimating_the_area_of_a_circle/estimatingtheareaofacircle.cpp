#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double r, m, c;
	// Variables to hold the input

	double pi = atan(1) * 4;
	cout << fixed << showpoint << setprecision(9);
	// Sets the output acurracy

	while(true)
	{
		cin >> r >> m >> c;
		// Take in the input

		if (r == 0)
		{
			break;
			// Break at the end of the input
		}

		cout << pi * r * r << " " << (c / m) * (r+r) * (r+r) << endl;
		// Calculate then output the answer the estimate is the radius plus the radius 
		// to get the side length of the square then squared to get the area then 
		// multiplied by the ratio of hits to estimate the circle area
	}

	return 0;
}