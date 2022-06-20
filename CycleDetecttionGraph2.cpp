#include <iostream>
#include <queue>
#include <list>
using namespace std;

// Cycle Detection Graph: for Undirected Graph...

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        (this)->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycle_helper(int node, bool *&visited, int parent)
    {
        // visiting a node...
        visited[node] = true;

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                bool cycle_hai = cycle_helper(nbr, visited, node);
                if (cycle_hai == true)
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool cycle_detect()
    {
        bool *visited = new bool[v];

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        return cycle_helper(0, visited, 0);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(4, 2);

    if (g.cycle_detect())
    {
        cout << "Cycle is present." << endl;
    }
    else
    {
        cout << "Cycle is not present." << endl;
    }

    return 0;
}