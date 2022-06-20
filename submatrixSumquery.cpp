#include <iostream>
using namespace std;

// Sub-matrix sum query:

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

    for (int i = 0; i < m; i++)
    {
        int alpha = 0;
        for (int j = 0; j < n; j++)
        {
            alpha += arr[i][j];
            arr[i][j] = alpha;
        }
    }

    for (int j = 0; j < n; j++)
    {
        int alpha = 0;
        for (int i = 0; i < m; i++)
        {
            alpha += arr[i][j];
            arr[i][j] = alpha;
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ti, tj, bi, bj;
    cout << "Enter the queries:" << endl;
    cin >> ti >> tj >> bi >> bj;

    cout << "Sum of Sub-array:" << endl;

    int sum = 0;

    if ((ti - 1) < 0 and (tj - 1) < 0)
    {
        sum = sum + arr[bi][bj];
        cout << sum << endl;
    }
    else if ((ti - 1) < 0 and (tj - 1) >= 0)
    {
        sum = sum + arr[bi][bj] - arr[bi][tj - 1];
        cout << sum << endl;
    }
    else if ((ti - 1) >= 0 and (tj - 1) < 0)
    {
        sum = sum + arr[bi][bj] - arr[ti - 1][bj];
        cout << sum << endl;
    }
    else if ((ti - 1) >= 0 and (tj - 1) >= 0 and bi <= m and bj <= n)
    {
        sum = sum + arr[bi][bj] - arr[ti - 1][bj] - arr[bi][tj - 1] + arr[ti - 1][tj - 1];
        cout << sum << endl;
    }
    else
    {
        cout << "Wrong queries" << endl;
    }

    return 0;
}
