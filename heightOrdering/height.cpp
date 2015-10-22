#include <iostream>

using namespace std;

int addStudent(int kid, int spot, int max, int line[20])
{
	int temp1;//To hold the one being placed
	int temp2;//To hold the one being moved to the next one
	temp1 = line[spot];
	line[spot] = kid; //Insert the kid

	int count = 0;
	for (int s = spot + 1; s <= max; s++)//loop from the current spot to the end of the current line
	{
		temp2 = line[s];//grab the kid being moved
		line[s] = temp1;//Place the kid that was being moved
		temp1 = temp2;//Get the next case ready
		++count;
	}

	return count;
}

int main()
{
	int p;
	cin >> p;

	int trial;
	int kids[20];
	int count = 0;
	int hold;

	for (int s = 0; s < 20; ++s)//Initialize array
	{
		kids[s] = 0;
	}


	for (int test = 1; test < p + 1; ++test)
	{
		cin >> trial;//take in their case num
		cin >> kids[0];//Grab the first student

		for (int i = 1; i < 20; ++i)//loop for each student
		{
			cin >> hold;//grab next student
			
			if (hold > kids[i - 1])//If bigger than the current biggest
			{
				kids[i] = hold;//Put the kid in the line (no moves)
			}
			else
			{
				int num;
				for (num = i - 1; num >= 0; --num)//loop to find the right student
				{
					if (hold > kids[num])//If found spot in line
					{
						count += addStudent(hold, num + 1, i, kids);
						break;
					}

					if (num == 0)
					{
						count += addStudent(hold, 0, i, kids);
						break;
					}
				}
			}
		}


		cout << trial << " " << count << endl; //Output
		count = 0; //Set up next trail
	}
	//system("pause>nul");
	return 0;
}