#include <iostream>
using namespace std;

// two different methods to find first index.

int linearSearch(int *arr, int n, int i, int k)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == k)
    {
        return i;
    }
    else
    {
        return linearSearch(arr, n, i + 1, k);
    }
}

int firstOccurence(int *arr, int n, int k)
{
    if (n == 0)
    {
        return -1;
    }

    if (arr[0] == k)
    {
        return 0;
    }
    int i = firstOccurence(arr + 1, n - 1, k);
    if (i == -1)
    {
        return -1;
    }
    return (i + 1);
}

int main()
{
    int k;
    cin >> k;
    int arr[] = {1, 20, 67, 78, 44, 44, 10, 11};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;

    cout << linearSearch(arr, n, i, k) << endl;

    cout << firstOccurence(arr, n, k) << endl;

    return 0;
}
