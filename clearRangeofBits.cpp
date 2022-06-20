#include <iostream>
using namespace std;

int clearLastBits(int n, int i)
{
    int mask = -1 << (i + 1);
    return (n & mask);
}

int clearBitsItoJ(int n, int i, int j)
{
    int a = (~0) << (i + 1);
    int b = (1 << j) - 1; // 2^n - 1 
    int mask = a | b;
    n = n & mask;
    return n;
}

int main()
{
    int n = 127;
    int i = 5;
    int j = 2;
    cout << clearLastBits(n, i) << endl;

    cout << clearBitsItoJ(n, i, j) << endl;

    return 0;
}
