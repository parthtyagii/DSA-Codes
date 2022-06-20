#include <iostream>
#include <vector>
using namespace std;

// Heaps: how to create heaps...

class Heap
{

    vector<int> v;
    bool minHeap;
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

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);

        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx=parent;
            parent=idx/2;
        }
    }

}

int
main()
{

    return 0;
}