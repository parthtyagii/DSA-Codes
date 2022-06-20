#include <iostream>
using namespace std;

long long tiling(long long n)
{
    if (n <= 3)
    {
        return 1;
    }

    long long x = tiling(n - 1) + tiling(n - 4);

    return x;
}

int main()
{
    long long n;
    cout << "Value of n: ";
    cin >> n;

    cout << tiling(n) << endl;

    return 0;
}