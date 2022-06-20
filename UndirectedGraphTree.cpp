#include <iostream>
#include <queue>
#include <list>
using namespace std;

// Undirected Graph is a Tree or Not: using BFS...

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

    bool its_tree()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;
        visited[0] = true;
        parent[0] = 0;

        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : l[node])
            {
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return false;
                }
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        return true;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    if (g.its_tree())
    {
        cout << "Yes! it is a tree." << endl;
    }
    else
    {
        cout << "No! it is not a tree." << endl;
    }

    return 0;
}