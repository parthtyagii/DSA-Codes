#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

// Max sum 2D sun matrix: Row and cloumn wise sorted

int main()
{
    int m, n;
    cout << "Enter no. of rows and column:" << endl;
    cin >> m >> n;
    int arr[100][100];
    int cumarr[100][100];
    cout << "Enter the values in 2D array" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int bi = m - 1; bi >= 0; bi--)
    {
        int alpha = 0;
        for (int bj = n - 1; bj >= 0; bj--)
        {
            alpha += arr[bi][bj];
            arr[bi][bj] = alpha;
        }
    }

    for (int bj = n - 1; bj >= 0; bj--)
    {
        int alpha = 0;
        for (int bi = m - 1; bi >= 0; bi--)
        {
            alpha += arr[bi][bj];
            arr[bi][bj] = alpha;
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Max sum of a sub matrix:" << endl;
    long int sum = INT_MIN;
    long int csum = 0;
    // for (int i = m; i >= 0; i--)
    // {
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             csum = arr[i][j];
    //             // if (csum >sum)
    //             // {
    //             //     sum = csum;
    //             // }
    //             sum = max(csum, sum);
    //         }
    //     }
    // }

    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            csum = arr[i][j];
            sum = max(sum, csum);
        }
    }

    cout << sum << endl;

    return 0;
}
