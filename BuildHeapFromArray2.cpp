#include <iostream>
#include <vector>
using namespace std;

// Build Heap from Array...in-place...o(N).

bool minHeap = true;

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

void heapify(vector<int> &v, int idx)
{
    int left = 2 * idx;
    int right = 2 * idx + 1;

    int min_idx = idx;
    int last_idx = v.size() - 1;

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
        heapify(v, min_idx);
    }

    return;
}

void BuildHeap(vector<int> &v)
{

    int i = (v.size() - 1) / 2;
    for (i; i >= 1; i--)
    {
        heapify(v, i);
    }
}

void Print(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    Print(v);

    BuildHeap(v);
    Print(v);

    return 0;
}