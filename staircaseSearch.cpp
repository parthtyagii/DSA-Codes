#include <iostream>
using namespace std;

// Staircase Method: for row and column wise sorted array.

void staircase(int arr[100][100], int n, int k)
{
    int row = 0;
    int col = n - 1;
    int alpha = 0;
    while (row <= n - 1 and col >= 0)
    {
        alpha = arr[row][col];
        if (alpha == k)
        {
            cout << "row: " << row << endl
                 << "column: " << col << endl;
            break;
        }

        else if (alpha > k)
        {
            col--;
        }

        else if (alpha < k)
        {
            row++;
        }
    }

    if (row > n - 1 or col < 0)
    {
        cout << "'Your no. is not present in given array.'" << endl;
    }
}

int main()
{
    int n, k;
    cout << "Enter the order of matrix: ";
    cin >> n;
    cout << "Enter the values in matrix: " << endl;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Enter the no. you want to search: ";
    cin >> k;

    cout << "Position of your no. in array: " << endl;
    staircase(arr, n, k);

    return 0;
}
