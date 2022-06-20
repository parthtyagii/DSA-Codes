#include <iostream>
#include <climits>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Coin Change: complexity - O(TN)

// Top to Bottom approach:
int CoinChange1(int n, int coins[], int T, int dp[])
{
    // base case:
    if (n == 0)
    {
        return 0;
    }

    // look up:
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        if ((n - coins[i]) >= 0)
        {
            int subProblem = CoinChange1(n - coins[i], coins, T, dp);
            ans = min(ans, subProblem + 1);
        }
        dp[n] = ans;
    }
    return dp[n];
}

// Bottom Up approach:
int CoinChange2(int n, int coins[], int T)
{
    int dp[100] = {0};

    for (int i = 1; i <= n; i++)
    {
        // initialize dp[i]=INT_MAX....
        dp[i] = INT_MAX;

        for (int j = 0; j < T; j++)
        {
            if (i - coins[j] >= 0)
            {
                int subProblem = i - coins[j];
                dp[i] = min(dp[i], dp[subProblem] + 1);
            }
        }
    }
    return dp[n];
}

int main()
{
    int n = 15;
    int coins[] = {1, 7, 10};
    int T = sizeof(coins) / sizeof(int);
    int dp[10000] = {0};

    cout << "First approach: ";
    cout << CoinChange1(n, coins, T, dp) << endl;

    cout << "Second approach: ";
    cout << CoinChange2(n, coins, T) << endl;

    return 0;
}