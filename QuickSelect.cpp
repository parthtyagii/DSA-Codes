#include <iostream>
using namespace std;

// Quickselect: O(N) complexity (avg.)....
// To find the kth smallest or largest element.
// ....somewhat like quickselect...

int pivot(int *arr, int s, int e)
{
    int i = s - 1;
    int j = s;

    while (j <= e)
    {
        if (arr[j] <= arr[e])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    return i;
}

void QuickSelect(int *arr, int s, int e, int k)
{
    if (s > e)
    {
        return;
    }

    int p = pivot(arr, s, e);

    if (p == k)
    {
        cout << arr[p] << endl;
        return;
    }

    if (p < k)
    {
        QuickSelect(arr, p + 1, e, k);
    }
    else
    {
        QuickSelect(arr, s, p - 1, k);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    QuickSelect(arr, 0, n - 1, n - k);

    return 0;
}