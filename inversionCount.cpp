#include <iostream>
using namespace std;

int merge(int *arr, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int k = s;
    int temp[1000];
    int count = 0;

    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            //here,
            count += mid - i + 1;
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

    for (int x = s; x <= e; x++)
    {
        arr[x] = temp[x];
    }

    return count;
}

int inversionCount(int *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;

    int x = inversionCount(arr, s, mid);
    int y = inversionCount(arr, mid + 1, e);
    int z = merge(arr, s, e);

    return (x + y + z);
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr) / sizeof(int);
    int s = 0;
    int e = n - 1;

    cout << inversionCount(arr, s, e) << endl;

    return 0;
}