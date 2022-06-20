#include <iostream>
using namespace std;

float squareRoot(int n, int p)
{
    int s = 0;
    int e = n;
    float x = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            x = mid;
            s = mid + 1;
        }
    }

    // for float number: brute force method
    float inc = 0.1;
    for (int i = 1; i <= p; i++)
    {
        while (x * x <= n)
        {
            x = x + inc;
        }
        x = x - inc;
        inc = inc / 10;
    }

    return x;
}

int main()
{

    int p, n;
    cin >> n >> p;

    cout << squareRoot(n, p) << endl;

    return 0;
}
