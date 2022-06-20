#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Vertical Order Print: Binary Tree using Hashmap.

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void nodeAtIndx(node *root, map<int, vector<int>> &m, int d)
{
    if (root == NULL)
    {
        return;
    }

    m[d].push_back(root->data);
    nodeAtIndx(root->left, m, d - 1);
    nodeAtIndx(root->right, m, d + 1);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(6);
    root->left->right = new node(7);

    root->right->right = new node(5);
    root->right->left = new node(4);
    root->right->left->left = new node(8);

    map<int, vector<int>> m;
    int d = 0;
    nodeAtIndx(root, m, d);

    // iteration:
    for (auto p : m)
    {
        for (auto x : p.second)
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}