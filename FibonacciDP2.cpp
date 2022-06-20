#include <iostream>
using namespace std;

// Bottom-Up: using array and space optimization technique...

int Fibo1(int n)
{
    // here, space complexity is: O(N)
    int dp[100] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int Fibo2(long long n)
{
    // here, space complexity is: O(1)
    long long a = 0;
    long long b = 1;
    long long c;
    for (long long i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    long long n;
    cin >> n;

    cout << "First approach: ";
    cout << Fibo1(n) << endl;

    cout << "Second approach: ";
    cout << Fibo1(n) << endl;

    return 0;
}