#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

int rollDice() //generate 2 numbers to calc sum
{
	int die1;
	int die2;
	int worksum = 0;
	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	worksum = die1 + die2;
	cout << "You rolled :" << die1 << " " << "and " << die2 << " " << " = " << worksum << endl;
	return worksum;

}
 
int main()
{
	enum status {CONTINUE,WON,LOST};
	int sum; char restart; int mypoint;
	status gamestatus;
	srand(time(0));
	sum = rollDice();			//begin first round of rolls
	switch (sum)
	{
	case 7:						//7,11 win
	case 11:
		gamestatus = WON;
		break;
	case 2:						//2,3,12, lose
	case 3:
	case 12:
		gamestatus = LOST;
		break;
	default:					//continue playing with your point
		gamestatus = CONTINUE;
		mypoint = sum;
		cout << "My point is: " << " " << mypoint << endl;
		break;
	}

	while (gamestatus == CONTINUE)	//continue and start another round
	{
		sum = rollDice();
		if (sum == mypoint)			//win is sum of roll is your point
			gamestatus = WON;
		else
			if(sum==7)				//lose if sum is 7 before hitting point
				gamestatus = LOST;

	}

	if (gamestatus == WON)
		cout << "YOU WIN!" << endl;
	else
		cout << "YOU LOST..." << endl;
	
	cout << "Would you like to play again? (y/n)" << endl;	//play again
	cin >> restart;
	if (restart == 'y')
	{
		main();
	}
	else if (restart == 'n')
	{
		return 0;
	}
	
}

/*
You rolled :6 and 2  = 8
My point is:  8
You rolled :2 and 3  = 5
You rolled :2 and 6  = 8
YOU WIN!
Would you like to play again? (y/n)
y
You rolled :1 and 5  = 6
My point is:  6
You rolled :4 and 2  = 6
YOU WIN!
Would you like to play again? (y/n)
y
You rolled :1 and 2  = 3
YOU LOST...
Would you like to play again? (y/n)
y
You rolled :5 and 4  = 9
My point is:  9
You rolled :1 and 6  = 7
YOU LOST...
Would you like to play again? (y/n)
y
You rolled :5 and 1  = 6
My point is:  6
You rolled :3 and 5  = 8
You rolled :2 and 5  = 7
YOU LOST...
Would you like to play again? (y/n)
n
*/

