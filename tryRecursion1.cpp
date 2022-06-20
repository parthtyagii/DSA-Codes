#include <iostream>
using namespace std;

// Using Recursion: (a multiply b)
long long multiply(long long x, long long y, long long n)
{
    if (x == 0)
    {
        return 0;
    }
    x--;
    n = multiply(x, y, n);
    n = n + y;
    return n;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long x = min(a, b);
    long long y = max(a, b);
    long long n = 0;

    cout << multiply(x, y, n) << endl;

    return 0;
}