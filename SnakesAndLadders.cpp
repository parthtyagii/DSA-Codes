#include <iostream>
#include <list>
#include <climits>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
using namespace std;

// Snakes and Ladders:

class Graph
{
    unordered_map<int, list<int>> m;

public:
    void addEdge(int x, int y)
    {
        m[x].push_back(y);
        // m[y].push_back(x);
    }

    int Shortest(int n)
    {
        int *dist = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            dist[i] = INT_MAX;
        }

        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : m[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        int ans = dist[n];
        delete[] dist;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        Graph g;
        int n, ladders, snakes;
        cin >> n >> ladders >> snakes;

        int die[n + 1] = {0};

        // ladders...
        for (int i = 1; i <= ladders; i++)
        {
            int a, b;
            cin >> a >> b;

            die[a] = b - a;
        }

        // snakes...
        for (int i = 1; i <= ladders; i++)
        {
            int a, b;
            cin >> a >> b;

            die[a] = b - a;
        }

        // edges...
        for (int i = 1; i <= n; i++)
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                int to = i + dice;
                to += die[to];

                if (to <= n)
                {
                    g.addEdge(i, to);
                }
            }
        }
        g.addEdge(n, n);

        cout << g.Shortest(n) << endl;
    }

    return 0;
}