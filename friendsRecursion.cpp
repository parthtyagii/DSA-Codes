#include <iostream>
using namespace std;

long long friends(long long n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    long long ans = friends(n - 1) + (n - 1) * friends(n - 2);

    return ans;
}

int main()
{
    long long n;
    cin >> n;

    cout << friends(n) << endl;

    return 0;
}