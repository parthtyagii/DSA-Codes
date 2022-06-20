#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <list>
using namespace std;

// Topological Sort: for Directed Acyclic Graph...

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);
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

    void DFS_helper(T src, unordered_map<T, bool> &visited, list<T> &order)
    {
        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                DFS_helper(nbr, visited, order);
            }
        }

        order.push_front(src);

        return;
    }

    // Topological Sort:
    void Topological()
    {
        unordered_map<T, bool> visited;
        list<T> order;

        for (auto P : l)
        {
            visited[P.first] = false;
        }

        // for all nodes...
        for (auto P : l)
        {
            T node = P.first;
            if (!visited[node])
            {
                DFS_helper(node, visited, order);
            }
        }

        for (auto node : order)
        {
            cout << node << " ";
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Z", "X");
    g.addEdge("X", "A");
    g.addEdge("X", "B");
    g.addEdge("X", "C");
    g.addEdge("Z", "Y");
    g.addEdge("Y", "A");

    g.Topological();

    return 0;
}