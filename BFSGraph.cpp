#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

// Breadth First Search: some what like level order traversal in Tree...

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
            // checking for all the connected nodes of "node"...
            for (auto nbr : l[node])
            {
                // checking if each node is already visited or not...
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
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
    g.BFS(3);

    return 0;
}