#include <iostream>
using namespace std;

// Top-Down approach:

int Fibo(int n, int dp[])
{
    // base case:
    if (n == 0 or n == 1)
    {
        return n;
    }

    // Look up:
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans;
    ans = Fibo(n - 1, dp) + Fibo(n - 2, dp);
    dp[n] = ans;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[10000];
    cout << Fibo(n, dp) << endl;

    return 0;
}