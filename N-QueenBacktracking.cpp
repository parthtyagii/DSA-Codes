#include <iostream>
using namespace std;

bool isSafe(int arr[10][10], int i, int j, int n)
{

    // check column:
    for (int idx = 0; idx < n; idx++)
    {
        if (arr[idx][j] == 1)
        {
            return false;
        }
    }

    int x = i;
    int y = j;
    // checking right diagnol:
    while (x >= 0 and y >= 0)
    {
        if (arr[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    int p = i, q = j;
    // checking left diagnol:
    while (p >= 0 and q < n)
    {
        if (arr[p][q] == 1)
        {
            return false;
        }
        p--;
        q++;
    }

    return true;
}

bool placeQueen(int arr[10][10], int i, int n)
{
    // Base case:
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    cout << "Q"
                         << " ";
                }
                else
                {
                    cout << "_"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << endl;

        // return true;
        return false; // ---> For all possible arrangements.
    }

    for (int j = 0; j < n; j++)
    {
        // check if current i,j position can hold queen:
        if (isSafe(arr, i, j, n))
        {
            arr[i][j] = 1;

            // check next i,j of next wor can hold queen:
            bool nextQueenRakhPaye = placeQueen(arr, i + 1, n);
            if (nextQueenRakhPaye)
            {
                return true;
            }

            // Backtracking: if we can't place queen in next row then we change the position of queen in current row.
            arr[i][j] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[10][10] = {0};

    bool alpha = placeQueen(arr, 0, n);
    if (alpha == false)
    {
        cout << "No further arrangements are possible." << endl;
    }

    return 0;
}