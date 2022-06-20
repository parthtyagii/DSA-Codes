#include <iostream>
#include <iomanip>
using namespace std;

// Spiral print:

void spiralprint(int arr[100][100], int r, int c)
{
	int scol = 0;
	int ecol = c - 1;
	int srow = 0;
	int erow = r - 1;

	// // Below while condition will work perfectly square matrices but not when number no. rows are odd.

	// while (erow >= srow and ecol >= scol)
	// {

	// 	// first row for
	// 	for (int i = scol; i <= ecol; i++)
	// 	{
	// 		cout << arr[srow][i] << ", ";
	// 	}
	// 	srow++;

	// 	// last column for
	// 	for (int i = srow; i <= erow; i++)
	// 	{
	// 		cout << arr[i][ecol] << ", ";
	// 	}
	// 	ecol--;

	// 	// last row
	// 	if (erow > srow)
	// 	{

	// 		for (int i = ecol; i >= scol; i--)
	// 		{
	// 			cout << arr[erow][i] << ", ";
	// 		}
	// 		erow--;
	// 	}

	// 	// first column
	// 	if (ecol > scol)
	// 	{
	// 		for (int i = erow; i >= srow; i--)
	// 		{
	// 			cout << arr[i][scol] << ", ";
	// 		}
	// 		scol++;
	// 	}
	// }

	// spiral print: 2nd method
	int dir = 0;

	while (srow <= erow and scol <= ecol)
	{
		if (dir == 0)
		{
			for (int i = scol; i <= ecol; i++)
			{
				cout << arr[srow][i] << " ";
			}

			srow++;
		}
		else if (dir == 1)
		{
			for (int i = srow; i <= erow; i++)
			{
				cout << arr[i][ecol] << " ";
			}
			ecol--;
		}
		else if (dir == 2)
		{
			for (int i = ecol; i >= scol; i--)
			{
				cout << arr[erow][i] << " ";
			}
			erow--;
		}
		else if (dir == 3)
		{
			for (int i = erow; i >= srow; i--)
			{
				cout << arr[i][scol] << " ";
			}
			scol++;
		}

		dir = (dir + 1) % 4;
	}

	cout << "END" << endl;
}

int main()
{
	int arr[100][100];
	int r, c;
	int val = 1;
	cout << "Enter the no. of rows and columns:" << endl;
	cin >> r >> c;

	cout << "Your 2D-array:" << endl;

	for (int row = 0; row < r; row++)
	{
		for (int col = 0; col < c; col++)
		{
			arr[row][col] = val;
			cout << setw(3) << arr[row][col] << " ";
			val++;
		}
		cout << endl;
	}
	cout << "Spiral Print:" << endl;

	spiralprint(arr, r, c);

	return 0;
}