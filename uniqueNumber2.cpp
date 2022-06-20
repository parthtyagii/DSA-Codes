#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int res = 0;
    // we will get "a^b".
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res = res ^ arr[i];
    }

    int copi = res;
    int pos = 0;
    // first or any position at which set bit is present in "a^b".
    while ((copi & 1) != 1)
    {
        pos++;
        copi = (copi >> 1);
    }

    int mask = (1 << pos);
    int a = 0;
    int b = 0;
    // we will get our first number "a".
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & mask) > 0)
        {
            a = a ^ arr[i];
        }
    }
    b = a ^ res;

    cout << min(a, b) << " " << max(a, b) << endl;

    return 0;
}

