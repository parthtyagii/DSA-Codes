#include <iostream>
#include <vector>
using namespace std;

void primeFactor(int n)
{
    vector<pair<int, int>> v;
    for (int i = 2; i * i <= n; i++)
    {
        // keep dividing till n is divisible by i.
        int count = 0;
        if ((n % i) == 0)
        {
            while ((n % i) == 0)
            {
                n = n / i;
                count++;
            }
            v.push_back(make_pair(i, count));
        }
    }

    if (n != 1)
    {
        // when n is not divisible, then it is itself a prime number.
        v.push_back(make_pair(n, 1));
    }

    // Print prime factors:
    for (auto x : v)
    {
        cout << x.first << "^" << x.second << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    primeFactor(n);

    return 0;
}