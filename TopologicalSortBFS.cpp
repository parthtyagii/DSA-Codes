#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <list>
using namespace std;

// Topological Sort: for Directed Acyclic Graph...

// for integers only....we can make it generic using maps.
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
    }

    void Topological()
    {
        // int *degree = new int[v];
        // initializing degree of each node as "0"...
        // for (int i = 0; i < v; i++)
        // {
        //     degree[i] = 0;
        // }
        unordered_map<int,int>degree;

        // calculating actual degree(dependency) of each node...
        for (int i = 0; i < v; i++)
        {
            for (auto node : l[i])
            {
                degree[node]++;
            }
        }

        // pushing integers in queue with degree = 0...
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto nbr : l[node])
            {
                degree[nbr]--;

                if (degree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(0, 2);
    g.addEdge(4, 5);

    g.Topological();

    return 0;
}