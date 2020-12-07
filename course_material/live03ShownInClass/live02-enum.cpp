// Name        : live02-enum.cpp
//============================================================================
// Description : Example on enumeration
//============================================================================

#include <iostream>
#include <string>
using namespace std;

enum direction { north, east, south, west };
//               0,     1,    2,     3

string dirToText(direction dir);
direction turnRight(direction dir);
direction turnLeft(direction dir);

int main()
{
	direction dir = north;

    bool continueIteration = true;

	while (continueIteration) {
		cout << "The direction is: " << dirToText(dir) << endl;

		cout << "Turn (R)ight, (L)eft, or (Q)uit: ";
		char turn;
		cin >> turn;

		if (turn == 'r') {
			dir = turnRight(dir);
		} else if (turn == 'l') {
			dir = turnLeft(dir);
		} else {
			continueIteration = false;
		}
	}

	return 0;
}

string dirToText(direction dir)
{
	switch(dir) {
		case north:
			return "North";
		case south:
			return "South";
		case east:
			return "East";
		case west:
			return "West";
		default:
			return "Unknown";
	}
}

direction turnLeft(direction dir)
{
	direction newDir;
	switch(dir) {
		case north:
			newDir = west;
			break;
		case south:
			newDir = east;
			break;
		case east:
			newDir = north;
			break;
		case west:
			newDir = south;
			break;
		default:
			cout << "Waaaaat!" << endl;
			newDir = dir;
	}
	return newDir;
}

direction turnRight(direction dir)
{
	int newDir = (dir+1) % 4;
	return (direction)newDir;
}
