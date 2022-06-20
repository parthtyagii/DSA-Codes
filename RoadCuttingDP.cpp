#include <iostream>
#include <climits>
using namespace std;

// Road Cutting Problem:

// Top-Down approach:
int MaxPrice1(int prices[], int n, int dp[])
{
    // base case:
    if (n <= 0)
    {
        return 0;
    }

    // Look Up:
    if (dp[n] != 0)
    {
        return dp[n];
    }

    dp[n] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int current_price = prices[i] + MaxPrice1(prices, n - cut, dp);
        dp[n] = max(dp[n], current_price);
    }
    return dp[n];
}

// Bottom-Up approach:
int MaxPrice2(int prices[], int n)
{
    int dp[n + 1] = {0};

    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int current_price = prices[i] + dp[len - cut];
            ans = max(ans, current_price);
        }
        dp[len] = ans;
    }

    return dp[n];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    int dp[1000] = {0};

    cout << "First approach: ";
    cout << MaxPrice1(prices, n, dp) << endl;

    cout << "Second approach: ";
    cout << MaxPrice2(prices, n) << endl;

    return 0;
}