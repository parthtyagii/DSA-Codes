#include <iostream>
#include <vector>
using namespace std;

// Build Heap from Array...in-place...O(NlogN)

void BuildHeap(vector<int> &v)
{

    for (int i = 2; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;

        while (idx > 1 and v[parent] < v[idx])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
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
    // For Max Heap...
    vector<int> v{-1, 36, 7, 19, 100, 25, 2, 17, 1, 3, 0};
    Print(v);

    BuildHeap(v);
    Print(v);

    return 0;
}