#include <iostream>
#include <unordered_map>
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

    void DFS(T src)
    {
        unordered_map<T, bool> visited;

        for (auto P : l)
        {
            visited[P.first] = false;
        }

        DFS_helper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(2, 3);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(4, 5);
    g.addEdge(2, 1);
    g.addEdge(4, 3);

    g.DFS(1);

    return 0;
}