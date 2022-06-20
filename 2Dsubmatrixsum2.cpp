#include <iostream>
using namespace std;

// Sum of all sub matrix: Approach 2

int main()
{
    int m, n;
    cout << "Enter no. of rows and column:" << endl;
    cin >> m >> n;
    int arr[100][100];
    int cumarr[100][100];
    cout << "Enter the values in 2D array:" << endl;
    for (int i = 0; i < m; i++)
    {
        int alpha = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            alpha += arr[i][j];
            cumarr[i][j] = alpha; // Not necessary to make new array. We can manipulate 'arr[][]' as well.
        }
    }

    for (int i = 0; i < n; i++)
    {
        int beta = 0;
        for (int j = 0; j < m; j++)
        {
            beta += cumarr[j][i];
            cumarr[j][i] = beta;
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
                    if ((Ti - 1) < 0 and (Tj - 1) < 0)
                    {
                        sum = sum + cumarr[Bi][Bj];
                    }
                    else if ((Ti - 1) < 0 and (Tj - 1) >= 0)
                    {
                        sum = sum + cumarr[Bi][Bj] - cumarr[Bi][Tj - 1];
                    }
                    else if ((Ti - 1) >= 0 and (Tj - 1) < 0)
                    {
                        sum = sum + cumarr[Bi][Bj] - cumarr[Ti - 1][Bj];
                    }
                    else
                    {
                        sum = sum + cumarr[Bi][Bj] - cumarr[Ti - 1][Tj] - cumarr[Bi][Tj - 1] + cumarr[Ti - 1][Tj - 1];
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
