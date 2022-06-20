#include <iostream>
using namespace std;

void allOccur1(int *arr, int n, int i, int k)
{
    if (i == n)
    {
        return;
    }

    if (arr[i] == k)
    {
        cout << i << " ";
    }

    return allOccur1(arr, n, i + 1, k);
}

int allOccur2(int *arr, int n, int k, int i, int j, int *output)
{
    if (i == n)
    {
        return j;
    }

    if (arr[i] == k)
    {
        output[j] = i;
        return allOccur2(arr, n, k, i + 1, j + 1, output);
    }
    else
    {
        return allOccur2(arr, n, k, i + 1, j, output);
    }
}

int main()
{
    int k;
    cin >> k;
    int arr[] = {1, 2, 32, 345, 654, 2, 56, 2, 2, 45, 2};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;
    int j = 0;
    allOccur1(arr, n, i, k);
    cout << endl;

    int output[n];
    int alpha = allOccur2(arr, n, k, i, j, output);
    for (int i = 0; i < alpha; i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}