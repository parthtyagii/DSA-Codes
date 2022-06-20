#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int arr[9][9], int i, int j, int n, int number)
{

    for (int x = 0; x < n; x++)
    {
        if (arr[i][x] == number || arr[x][j] == number)
        {
            return false;
        }
    }

    int rn = sqrt(n);
    int m = (i / rn) * rn;
    int o = (j / rn) * rn;

    for (int x = m; x < m + 3; x++)
    {
        for (int y = o; y < o + 3; y++)
        {
            if (arr[x][y] == number)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudoku(int arr[9][9], int i, int j, int n)
{
    // Base case:
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    if (j == n)
    {
        return sudoku(arr, i + 1, 0, n);
    }

    if (arr[i][j] != 0)
    {
        return sudoku(arr, i, j + 1, n);
    }

    // Recursive case:
    for (int number = 1; number <= n; number++)
    {
        // Checking if current number can be placed or not.
        if (canPlace(arr, i, j, n, number))
        {
            arr[i][j] = number;

            bool hoPaya = sudoku(arr, i, j + 1, n);
            if (hoPaya == true)
            {
                return true;
            }
        }
    }

    // Backtracking:
    arr[i][j] = 0;

    return false;
}

int main()
{
    int arr[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                     {6, 0, 0, 1, 9, 5, 0, 0, 0},
                     {0, 9, 8, 0, 0, 0, 0, 6, 0},
                     {8, 0, 0, 0, 6, 0, 0, 0, 3},
                     {4, 0, 0, 8, 0, 3, 0, 0, 1},
                     {7, 0, 0, 0, 2, 0, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0},
                     {0, 0, 0, 4, 1, 9, 0, 0, 5},
                     {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    sudoku(arr, 0, 0, 9);

    return 0;
}