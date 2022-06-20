#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

// Graph implementation: Adjacency List...

// For integers only:
class Graph1
{
    int v;
    list<int> *l;

public:
    Graph1(int no)
    {
        v = no;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void Print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " --> ";
            for (auto p : l[i])
            {
                cout << p << " ";
            }
            cout << endl;
        }
    }
};

// Generic implementation:
class Graph2
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void AddEdge(string s, string conn, int len, bool bidirec)
    {
        l[s].push_back(make_pair(conn, len));
        if (bidirec)
        {
            l[conn].push_back(make_pair(s, len));
        }
    }

    void Print()
    {
        for (auto p : l)
        {
            string node = p.first;
            list<pair<string, int>> ans = p.second;
            cout << "vertex " << node << " --> ";
            for (auto x : ans)
            {
                cout << x.first << " " << x.second << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph1 G1(4);
    G1.addEdge(0, 1);
    G1.addEdge(0, 2);
    G1.addEdge(1, 2);
    G1.addEdge(2, 3);
    G1.Print();
    cout << endl;

    Graph2 G2;
    G2.AddEdge("A", "B", 20, true);
    G2.AddEdge("B", "D", 30, true);
    G2.AddEdge("A", "C", 10, true);
    G2.AddEdge("C", "D", 40, true);
    G2.AddEdge("A", "D", 50, false);
    G2.Print();
    cout << endl;

    return 0;
}