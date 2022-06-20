#include <iostream>
using namespace std;

int getBit(int n, int i)
{
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i)
{
    int mask = (1 << i);
    int ans = (n | mask);
    return ans;
}

int main()
{
    // To check if a number is odd or even by  getting last bit.
    int n, i;
    cin >> n >> i;
    int check = n & 1;
    if (check == 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }

    // Getting ith bit:

    cout << getBit(n, i) << endl;

    // Setting ith bit:

    cout << setBit(n, i) << endl;

    return 0;
}
