#include <iostream>

using namespace std;


bool isIsland(int left, int right, int arr[12])
{
	for (int i = left; i <= right; ++i)
	{
		if (arr[i] <= arr[left - 1] || arr[i] <= arr[right + 1])
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
		cin >> num;//test case num

		for (int s = 0; s < 12; ++s)//fill the array
		{
			cin >> seq[s];
		}


		count = 0;
		for (int i = 1; i < 11; ++i)//Find answer
		{
			for (int j = i; j < 11; ++j)
			{
				if (isIsland(i, j, seq))
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