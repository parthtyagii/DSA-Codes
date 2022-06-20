#include <iostream>
using namespace std;

// Sum of all sub matrix: Approach 1

int main()
{

    int m, n;
    cout << "Enter no. of rows and column:" << endl;
    cin >> m >> n;
    int arr[100][100];
    cout << "Enter the values in 2D array" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Sum of all possible 2D Sub-array:" << endl;

    long int sum = 0;
    for (int Ti = 0; Ti < m; Ti++)
    {
        for (int Tj = 0; Tj < n; Tj++)
        {
            for (int Bi = Ti; Bi < m; Bi++)
            {
                for (int Bj = Tj; Bj < n; Bj++)
                {
                    for (int i = Ti; i <= Bi; i++)
                    {
                        for (int j = Tj; j <= Bj; j++)
                        {
                            sum += arr[i][j];
                        }
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
