#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    long long extra[t];

    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;

        long long ans = 0;
        long long subSets = (1 << 8) - 1;
        for (long long i = 1; i <= subSets; i++)
        {
            long long num = i;
            long long denom = 1;
            int j = 0;
            int bits = __builtin_popcount(num);
            while (num > 0)
            {
                if (num & 1)
                {
                    denom = denom * primes[j];
                }
                num = (num >> 1);
                j++;
            }

            if (bits & 1)
            {
                ans += n / denom;
            }
            else
            {
                ans -= n / denom;
            }
        }

        extra[x] = ans;
    }

    for (int i = 0; i < t; i++)
    {
        cout << "Your answer of test case " << (i + 1) << " is: " << extra[i] << endl;
    }

    return 0;
}