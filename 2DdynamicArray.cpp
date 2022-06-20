#include <iostream>
#include <iomanip>
using namespace std;

// Allocating 2D Dynamic Array:

int main()
{
    int r, c;
    cin >> r >> c;
    int **arr = 0;

    // array of pointers
    arr = new int *[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c]{0}; //dynamic arrays to store values
    }

    int val = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = val;
            val++;
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}