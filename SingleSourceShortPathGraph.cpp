#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
#include <list>
using namespace std;

// Shortest distance of source node from each node...

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

    void sssp(T src)
    {
        unordered_map<int, int> dist;
        queue<T> q;

        for (auto p : l)
        {
            T node = p.first;
            dist[node] = INT_MAX;
        }

        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for (auto node_pair : l)
        {
            T node = node_pair.first;
            cout << "Distance of node " << node << " from source " << dist[node] << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.sssp(0);

    return 0;
}