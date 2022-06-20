#include <iostream>
using namespace std;

void clearBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

void updateBit(int &n, int i, int v)
{
    int mask = ~(1 << i);
    int change = n & mask;
    n = change | (v << i);
}

int main()
{
    // Clearing ith bit.
    int n, i, v;
    cin >> n >> i >> v;
    /* clearBit(n, i);
    cout << n << endl; */

    // Updating ith bit.
    updateBit(n, i, v);
    cout << n << endl;

    return 0;
}