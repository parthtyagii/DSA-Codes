#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Finding Minimum Spanning Tree(MST) in weighted graph:                                                                           

class Graph
{
    int V;
    vector<pair<int, int>> *l;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[V];
    }

    void addEdge(int x, int y, int weight)
    {
        l[x].push_back(make_pair(y, weight));
        l[y].push_back({x, weight});
    }

    int prims_mst()
    {
        // min heap...
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // mst set array...
        bool *visited = new bool[V]{false};
        int ans = 0;

        Q.push(make_pair(0, 0));

        while (!Q.empty())
        {
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (visited[to] == true)
            {
                continue;
            }

            ans += weight;
            visited[to] = true;

            for (auto x : l[to])
            {
                if (visited[x.first] == false)
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        
        delete[] visited;
        return ans;
    }
};

int main()
{
    Graph g(11);
    g.addEdge(0, 1, 0);
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

    cout << g.prims_mst() << endl;

    return 0;
}