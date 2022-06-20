#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Finding Minimum Spanning Tree(MST) in weighted graph:

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int Find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return parent[i] = Find(parent[i]);
    }

    void union_set(int a, int b)
    {
        int s1 = Find(a);
        int s2 = Find(b);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y, int weight)
    {
        edgeList.push_back({weight, x, y});
    }

    int kruskal()
    {
        // sort the edgelist...
        sort(edgeList.begin(), edgeList.end());

        // initialize DSU object:
        DSU s(V);

        int ans = 0;
        for (auto list : edgeList)
        {
            int weight = list[0];
            int x = list[1];
            int y = list[2];

            if (s.Find(x) != s.Find(y))
            {
                s.union_set(x, y);
                ans += weight;
            }
        }

        return ans;
    }
};

int main()
{
    Graph g(15);
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 3, 3);
    // g.addEdge(3, 2, 4);
    // g.addEdge(2, 0, 2);
    // g.addEdge(0, 3, 2);
    // g.addEdge(1, 2, 2);

    // cout << g.kruskal() << endl;

    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 9, 8);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 5, 3);
    g.addEdge(5, 9, 7);
    g.addEdge(5, 6, 3);
    g.addEdge(9, 6, 10);
    g.addEdge(9, 7, 8);
    g.addEdge(9, 8, 5);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 9);
    g.addEdge(7, 10, 2);
    g.addEdge(8, 10, 11);

    cout << g.kruskal() << endl;

    return 0;
}