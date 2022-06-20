#include <iostream>
using namespace std;

// Merge Sort: using Recursion

void merge(int *arr, int s, int e, int mid)
{
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    // merging sorted arrays.
    while (i <= mid && j <= e)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }

    // copying temp array to original array.
    for (int x = s; x <= e; x++)
    {
        arr[x] = temp[x];
    }
    return;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Now, merging sorted array:
    merge(arr, s, e, mid);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
