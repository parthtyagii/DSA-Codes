#include <iostream>
#include <vector>
using namespace std;

// HeapSort: in-place......O(NlogN).

bool minHeap = false;

bool compare(int a, int b)
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

void heapify(vector<int> &v, int idx, int size)
{
    int left = 2 * idx;
    int right = 2 * idx + 1;

    int min_idx = idx;
    int last_idx = size - 1;

    if (left <= last_idx && compare(v[left], v[idx]))
    {
        min_idx = left;
    }
    if (right <= last_idx and compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx, size);
    }

    return;
}

void BuildHeap(vector<int> &v)
{

    int i = (v.size() - 1) / 2;
    for (i; i >= 1; i--)
    {
        heapify(v, i, v.size());
    }
}

void HeapSort(vector<int> &arr)
{

    int n = arr.size();
    BuildHeap(arr); // O(N)...

    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);
        n--;
        heapify(arr, 1, n); // O(NLogN)...
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(-1);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }

    HeapSort(arr);

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}