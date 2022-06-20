#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{
    if (n == 1)
    {
        return;
    }
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    return bubbleSort(arr, n - 1);
}

void bubbleSortRecursive(int *arr, int n, int j)
{
    if (n == 1)
    {
        return;
    }

    if (j == n - 1)
    {
        return bubbleSortRecursive(arr, n - 1, 0);
    }
    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }
    bubbleSortRecursive(arr, n, j + 1);
}

int main()
{
    int arr[] = {3, 4, 5, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    // bubbleSort(arr, n);
    bubbleSortRecursive(arr, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}