#include <iostream>
using namespace std;

bool isPossible(long long n, long long m, long long x, long long y, long long mid)
{
    long long required = mid * x;
    long long available = m + (n - mid) * y;
    if (required <= available)
    {
        return true;
    }
    return false;
}

int main()
{
    long long n, m, x, y;
    cin >> n >> m >> x >> y;

    long long s = 0;
    long long e = n;
    long long ans = 0;
    while (s <= e)
    {
        if (n < 0 or m < 0 or x < 0 or y < 0)
        {
            return 0;
        }

        long long mid = (s + e) / 2;
        bool weCan = isPossible(n, m, x, y, mid);
        if (weCan)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
