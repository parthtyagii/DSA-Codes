#include <iostream>
#include <list>
using namespace std;

// Disjoint Union Set: cycle detection...O(N) complexity.

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y)
    {
        l.push_back(make_pair(x, y));
    }

    // Find: returns set...
    int Find(int i, int parent[])
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return Find(parent[i], parent);
    }

    // Union: merges two sets...
    void union_set(int a, int b, int parent[])
    {
        int s1 = Find(a, parent);
        int s2 = Find(b, parent);

        if (s1 != s2)
        {
            parent[s2] = s1;
        }
    }

    bool cycle_detect()
    {
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        for (auto edge : l)
        {
            int a = edge.first;
            int b = edge.second;

            int S1 = Find(a, parent);
            int S2 = Find(b, parent);

            if (S1 != S2)
            {
                union_set(a, b, parent);
            }
            else
            {
                cout << "cycle found!!" << endl;
                return true;
            }
        }

        delete[] parent;
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << g.cycle_detect() << endl;

    return 0;
}