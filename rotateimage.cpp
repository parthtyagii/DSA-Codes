#include <iostream>
#include <algorithm>
using namespace std;

// Rotate Image: rotating a square matrix.

void rotatefunc(int arr[100][100], int n)
{
    // first reverse the rows.
    for (int i = 0; i < n; i++)
    {
        int scol = 0;
        int ecol = n - 1;
        while (ecol > scol)
        {
            swap(arr[i][scol], arr[i][ecol]);
            scol++;
            ecol--;
        }
    }

    // Now, swap triangle above diagnol with triangle below diagnol or vice versa.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}

void rotatestl(int arr[100][100], int n)
{
    // first reverse.
    for (int i = 0; i < n; i++)
    {
        // using <algorithm> header file.
        reverse(arr[i], arr[i] + n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}

int main()
{
    int n;
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

    // We can use either way to rotate image:
    
    // rotatefunc(arr, n);
    rotatestl(arr, n);

    cout << "Your rotated matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
