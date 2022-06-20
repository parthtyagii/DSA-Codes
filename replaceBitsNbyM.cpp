#include <iostream>
using namespace std;

int clearBits(int n, int i, int j)
{
    int a = -1 << (i + 1);
    int b = (1 << j) - 1;
    int mask = a | b;
    return (mask & n);
}

int replaceNbyM(int n, int m, int i, int j)
{
    int cleared = clearBits(n, i, j);
    m = (m << j);
    n = cleared | m;
    return n;
}

int main()
{
    int n = 64;
    int m = 21;
    int i = 5;
    int j = 1;

    cout << replaceNbyM(n, m, i, j) << endl;

    return 0;
}