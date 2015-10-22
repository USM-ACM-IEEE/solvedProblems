#include <iostream>

using namespace std;


bool isIsland(int left, int right, int arr[12])
//This will take two ints to loop between to validate that between these two points is an island 
{
	for (int i = left; i <= right; ++i)
	//Iterates in between the left and the right elements to verify
	//	that they are greater than the left and right
	{
		if (arr[i] <= arr[left - 1] || arr[i] <= arr[right + 1])
		//If the current spot is not greater than or equal to the ending of the island
		//	return false, this would not be considered an island
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	int seq[12];
	int num;
	int count;
	for (int test = 1; test < t + 1; ++test)
	{
		cin >> num;
		//test case num

		for (int s = 0; s < 12; ++s)
		//fill the array
		{
			cin >> seq[s];
		}


		count = 0;
		for (int i = 1; i < 11; ++i)
		//Loop for the left checking position
		{
			for (int j = i; j < 11; ++j)
			//Loop for the right checking position
			{
				if (isIsland(i, j, seq))
				//If the current spot is an island
				{
					++count;
				}
			}
		}


		//output
		cout << num << " " << count << endl;
		
	}
	//system("pause>nul");
	return 0;
}