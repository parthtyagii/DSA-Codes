#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <cstring>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int int32_t

// Modulo Multiplicative Inverse:
int BinaryExponentiation(int a, int power, int m)
{
    int ans = 1;
    while (power > 0)
    {
        if (power & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        power >> 1;
    }
    return ans;
}

int main()
{
    //find nCk:
    // nCk = (n!)/(((n-k)!)*(k!))
    int n, k;
    cin >> n >> k;
    int m = 1e9 + 7;

    int fact[n];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }

    int numerator = fact[n];
    int denomenator = (fact[n - k] * fact[k]) % m;
    denomenator = BinaryExponentiation(denomenator,m-2,m)%m;

    cout << ((numerator * denomenator) % m) << endl;

    return 0;
}
