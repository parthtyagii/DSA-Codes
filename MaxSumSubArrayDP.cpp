#include <iostream>
using namespace std;

// Max Sum Sub-array:

int MaxSum1(int arr[], int n)
{
    int dp[100] = {0};
    if (arr[0] > 0)
    {
        dp[0] = arr[0];
    }

    int max_so_far = dp[0];

    for (int i = 0; i < n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }

    return max_so_far;
}

// We can further optimize this code by using variable instead of DP array.
// That will reduce our space complexity to O(1) from O(N).

int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << "First approach [O(N)]: ";
    cout << MaxSum1(arr, n) << endl;

    return 0;
}