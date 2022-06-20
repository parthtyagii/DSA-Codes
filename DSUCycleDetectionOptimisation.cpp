#include <iostream>
#include <list>
using namespace std;

// DSU with Optimisaiton: reducing complexity to O(1) approximately by applying two optimisations...
// --> Path Compression Optimisation: changes in Find fn {logN avg. complexity by this}
// --> Union by Rank: changes in Union fn

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

    // By making leader of the set as absolute parent...
    int Find(int i, int parent[])
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return parent[i] = Find(parent[i], parent);
    }

    void union_set(int a, int b, int parent[], int rank[])
    {
        int s1 = Find(a, parent);
        int s2 = Find(b, parent);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += s2;
            }
        }
    }

    bool cycle_detect()
    {
        int *parent = new int[V];
        int *rank = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto edge : l)
        {
            int a = edge.first;
            int b = edge.second;

            int S1 = Find(a, parent);
            int S2 = Find(b, parent);

            if (S1 != S2)
            {
                union_set(a, b, parent, rank);
            }
            else
            {
                return true;
            }
        }

        delete[] parent;
        delete[] rank;
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

    if (g.cycle_detect())
    {
        cout << "Cycle found!!" << endl;
    }
    else
    {
        cout << "Cycle not found!!" << endl;
    }

    return 0;
}