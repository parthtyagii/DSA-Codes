#include <iostream>
using namespace std;

// Sum of all aub matrix: Approach 3

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = (i + 1) * (j + 1);
            int y = (m - i) * (n - j);
            sum += arr[i][j] * x * y;
        }
    }

    cout << sum << endl;

    return 0;
}
