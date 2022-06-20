#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

// Depth First Search:

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void BFS(T src)
    {
        unordered_map<int, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void DFS_helper(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                DFS_helper(nbr, visited);
            }
        }
        return;
    }

    void Components()
    {
        unordered_map<T, bool> visited;

        for (auto P : l)
        {
            visited[P.first] = false;
        }

        // call DFS_helper functions to for all the nodes to get all the componets of the graphs...
        int connection = 0;
        for (auto P : l)
        {
            T node = P.first;
            if (!visited[node])
            {
                cout << "Connection " << connection << ": ";
                DFS_helper(node, visited);
                cout << endl;
                connection++;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(4, 0);
    g.addEdge(1, 0);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.addEdge(1, 2);
    g.addEdge(5, 6);
    g.addEdge(3, 0);
    g.addEdge(3, 2);

    g.Components();

    return 0;
}