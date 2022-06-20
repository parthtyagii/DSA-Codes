#include <iostream>
#include <climits>
using namespace std;

// Minimum steps to reach 1:

// Top to Bottom approach: (recursion + momoization)
int TopToBottom(int n, int dp[])
{
    // base case:
    if (n == 1)
    {
        return 0;
    }

    // look up:
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 2 == 0)
    {
        op1 = TopToBottom(n / 2, dp);
    }

    if (n % 3 == 0)
    {
        op2 = TopToBottom(n / 3, dp);
    }

    op3 = TopToBottom(n - 1, dp);

    int ans = min(op1, min(op3, op2)) + 1;
    dp[n] = ans;
    return ans;
}

// Bottom Up approach: using DP array...
int BottomUp(int n)
{
    int dp[10000] = {0};

    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if (i % 2 == 0)
        {
            op1 = dp[i / 2];
        }

        if (i % 3 == 0)
        {
            op2 = dp[i / 3];
        }

        op3 = dp[i - 1];

        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[10000] = {0};

    cout << "First approach: ";
    cout << TopToBottom(n, dp) << endl;

    cout << "Second approach: ";
    cout << BottomUp(n) << endl;

    return 0;
}