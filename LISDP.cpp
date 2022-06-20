#include <iostream>
#include <climits>
using namespace std;

// Longest Increasing Sub-sequences:

// Standard DP soln: O(N^2)
int SubSequence1(int *arr, int n)
{
    int dp[100] = {0};

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};
    int n = sizeof(arr) / sizeof(int);

    cout << "First approach: ";
    cout << SubSequence1(arr, n) << endl;

    return 0;
}