#include <iostream>
using namespace std;

// Quick Sort:

int partition(int *arr, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = arr[e];

    for (j; j <= e - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);

    return (i + 1);
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    // getting pivot:
    int p = partition(arr, s, e);

    // Sorting left part:
    quickSort(arr, s, p - 1);
    // Sorting right part:
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {2, 7, 8, 6, 1, 4, 5, 4};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}