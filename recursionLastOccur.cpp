#include <iostream>
using namespace std;

// two different methods to find last index.

int lastOccur1(int *arr, int n, int k)
{
    if (n == 0)
    {
        return -1;
    }
    int i = lastOccur1(arr + 1, n - 1, k);
    if (i == -1)
    {
        if (arr[0] == k)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    return (i + 1);
}

int lastOccur2(int *arr, int i, int k)
{
    if (i < 0)
    {
        return -1;
    }

    if (arr[i] == k)
    {
        return i;
    }
    else
    {
        return lastOccur2(arr, i - 1, k);
    }
}

int main()
{
    int k;
    cin >> k;
    int arr[] = {1, 5, 3, 34, 43, 4, 5, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    int i = n - 1;

    cout << lastOccur1(arr, n, k) << endl;
    cout << lastOccur2(arr, i, k) << endl;

    return 0;
}