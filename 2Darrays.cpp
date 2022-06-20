#include <iostream>
#include <iomanip>
using namespace std;

// Introduction to 2D Arrays:

int main()
{
    // data_type Array_name[rows][column];
    int arr[100][100] = {0};
    int i, j;
    cout << "Enter the no. of rows and column: " << endl;
    cin >> i >> j;
    int val = 1;
    cout << "Your 2D Array: " << endl;
    for (int row = 0; row < i; row++)
    {
        for (int col = 0; col < j; col++)
        {
            arr[row][col] = val;
            val++;
            cout << setw(3) << arr[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
