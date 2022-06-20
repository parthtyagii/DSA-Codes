#include <iostream>
#include <iomanip>
using namespace std;

// Wave print of 2D-array:

int main()
{
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

    // Wave Print:
    cout << "Wave Print of your array: " << endl;
    for (int col = 0; col < j; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < i; row++)
            {
                cout << arr[row][col] << ", ";
            }
        }
        else
        {
            for (int row = (i - 1); row >= 0; row--)
            {
                cout << arr[row][col] << ", ";
            }
        }
    }

    return 0;
}
