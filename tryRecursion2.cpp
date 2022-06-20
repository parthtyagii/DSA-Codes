#include <iostream>
using namespace std;

// Using Recursion: (a to the power b)
long long Power(long long a, long long b, long long n)
{
    if (b == 0)
    {
        return 1;
    }
    b--;
    n = Power(a, b, n);
    n = n * a;
    return n;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long n = 1;
    cout << Power(a, b, n) << endl;

    return 0;
}