// Name        : live02-enum.cpp
//============================================================================
// Description : Introduce structures, and draw a random maze
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>     /* Library containing functions such as
                           rand (a generator of random numbers) */
using namespace std;

// This function is defined below
int randomMaze();

// We declare here an enumeration type called "material"
enum material {wood, stone};

// We declare here a record type called "field"
struct field {
	int x;
	int y;
	bool isWall;
	material type;
};

// This function translates materials into characters, in order to display them
char character(material m) {
	switch(m) {
        case wood:
			return ' ';
		case stone:
			return '#';
		default:
			return '?';
    }
}

// Print the contents of a field structure
void printField(field f) {
	string typeStr = (f.type == wood) ? "wood" : "stone";
    cout << "Position (" << f.x << ", " << f.y << ") is made of " << typeStr;
	if (f.isWall) {
		cout << " and it contains a wall";
	}
	cout << endl;
}

int main() {
	cout << "The character of wood is: '" << character(wood) << "'" << endl;
	cout << "The character of stone is: '" << character(stone) << "'" << endl;

	field f1;
	f1.x = 0;
	f1.y = 1;
	f1.isWall = true;
	f1.type = stone;
	//printField(f1);

	field f2 = {1, 1, false, wood};
	//printField(f2);

    return randomMaze();
}

int randomMaze() {
	int n = 0;
	int m = 0;

	cout << "Enter the height of the field: ";
	cin >> n;
	cout << "Enter the width of the field: ";
	cin >> m;

	field **playground = new field*[n];
	for (int i=0; i<n; i++) {
		playground[i] = new field[m];
	}

	// building the playground (stone perimeter, wood inside)
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			// Note here how we access an element of an array
			// with playground[i][j]
			// and how we access the fields of a (field) record
			// with .x, .y, etc.
			playground[i][j].x=i;
			playground[i][j].y=j;
			playground[i][j].isWall = (i==0||i==(n-1)||j==0||j==(m-1)||(rand()%4)==0);
			if (playground[i][j].isWall) {
				playground[i][j].type=stone;
			} else {
				playground[i][j].type=wood;
			}
		}
	}

	// printing the playground
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << character(playground[i][j].type);
		}
		cout << endl;
	}

	// when memory is dynamically allocated, you have to deallocate it explicitly!
	for (int i=0; i<n; i++) {
		delete[] playground[i];
	}
	delete[] playground;

	return 0;
}

// Sample output:
//####
//#  #
//#  #
//# ##
//####
