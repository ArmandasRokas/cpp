// Name        : live02-enum.cpp
//============================================================================
// Description : Arrays
//============================================================================

#include <iostream>

using namespace std;

void printArray(int n, int array[])
{
	cout << "The array contains:" << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

const int ARRAY_SIZE = 2;
int main()
{
	/*
	 * An array specified at compile time
	 */
	int a1[] = { 3, 2, 1 };
	cout << "The memory location of a1 is: " << a1 << endl;
	printArray(3, a1);

	cout << "\n\n";

	/*
	 * An array of length specified at compile time
	 */
	int a2[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << "Value for element " << i << ": ";
		cin >> a2[i];
	}
	printArray(ARRAY_SIZE, a2);

	cout << "\n\n";

	/*
	 * An array of length specified at runtime
     * (Notice the use of "new int[]" and "delete[]")
	 */
	int n;
	cout << "Please enter the number of array elements: ";
	cin >> n;

    int* a3;
	a3 = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Value for element " << i << ": ";
		cin >> a3[i];
	}
	printArray(n, a3);
	delete[] a3;
	
	cout << "\n\n";

	/*
	 * An matrix of size n*n, where n is specified at runtime
     * (Notice that we use a pointer to an array of pointers to integers)
	 */
	cout << "Please enter the size of the nxn matrix: ";
	cin >> n;
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	int x, y, v;
	cout << "Enter the matrix coordinates and value: ";
	cin >> x >> y >> v;
	matrix[x][y] = v;
	cout << "CHECK: the matrix now contains: " << matrix[x][y] << endl;

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
