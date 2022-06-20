#include <iostream>
#include <queue>
#include <climits>
#include <unordered_map>
#include <set>
#include <list>
using namespace std;

// Dijkstra's Algo: shortest source path distance for weighted graph...

template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addEdge(T u, T v, int dist, bool bidirec = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidirec)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }

    void Print()
    {
        for (auto city : m)
        {
            cout << city.first << "-->";
            for (auto connected : city.second)
            {
                cout << "(" << connected.first << "," << connected.second << ")";
            }
            cout << endl;
        }
    }

    void dijkstra(T src)
    {
        unordered_map<T, int> dist;
        for (auto j : m)
        {
            dist[j.first] = INT_MAX;
        }

        // making set to find out city with min dist...
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            // pair at the front..
            auto P = *(s.begin());
            T parent = P.second;
            int parentDist = P.first;
            s.erase(s.begin());

            // iterating over the neighbour of given node...
            for (auto childPair : m[parent])
            {
                if (parentDist + childPair.second < dist[childPair.first])
                {

                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(make_pair(dist[dest], dest));
                    }

                    dist[dest] = parentDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

        for (auto d : dist)
        {
            cout << d.first << " is located at distance " << d.second << " from source." << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("A", "D", 1);
    g.addEdge("A", "J", 4);
    g.addEdge("J", "D", 2);
    g.addEdge("J", "M", 8);
    g.addEdge("B", "Ag", 2);
    g.addEdge("M", "B", 3);
    g.addEdge("Ag", "D", 1);

    // g.Print();
    g.dijkstra("A");

    return 0;
}