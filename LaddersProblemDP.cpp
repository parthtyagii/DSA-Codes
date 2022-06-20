#include <iostream>
using namespace std;

// Ladders Problem:
// Basically, we are counting the number of times we are hitting the base case.

// Top-Down approach:
int Ladders_TopDown(int n, int k, int dp[])
{
    // base case:
    if (n == 0)
    {
        return 1;
    }
    // Look up:
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ways += Ladders_TopDown(n - i, k, dp);
        }
    }
    return dp[n] = ways;
}

// Bottom Up approach:
int Ladders_BottomUp(int n, int k)
{
    int dp[100] = {0};

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int x = 1; x <= k; x++)
        {
            if (i - x >= 0)
            {
                dp[i] += dp[i - x];
            }
        }
    }

    return dp[n];
}

// Optimized approach: without using loop to calculate sum...
int Ladders(int n, int k)
{
    int dp[100] = {0};

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - 1 - k];
    }
    return dp[n];
}

int main()
{
    int n, k;
    int dp[1000] = {0};
    cin >> n >> k;

    cout << "First approach: ";
    cout << Ladders_TopDown(n, k, dp) << endl;

    cout << "Second approach: ";
    cout << Ladders_BottomUp(n, k) << endl;

    cout << "Third approach: ";
    cout << Ladders(n, k) << endl;

    return 0;
}