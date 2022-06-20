#include <iostream>
using namespace std;

// Find shortest distance between any two given nodes in a Binary Tree:

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *BinaryTree()
{
    int d;
    cin >> d;

    // bsae case:
    if (d == -1)
    {
        return NULL;
    }

    // recursive call:
    node *root = new node(d);
    (root)->left = BinaryTree();
    (root)->right = BinaryTree();

    return root;
}

node *LCA(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a or root->data == b)
    {
        return root;
    }

    node *lside = LCA(root->left, a, b);
    node *rside = LCA(root->right, a, b);

    if (lside != NULL and rside != NULL)
    {
        return root;
    }

    if (lside != NULL)
    {
        return lside;
    }
    return rside;
}

int FindLevel(node *root, int key, int level)
{
    // base case:
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
    {
        return level;
    }

    int ls = FindLevel(root->left, key, level + 1);
    if (ls != -1)
    {
        return ls;
    }

    int rs = FindLevel(root->right, key, level + 1);
    if (rs != -1)
    {
        return rs;
    }
}

int Shortest(node *root, int node1, int node2)
{
    node *ances = LCA(root, node1, node2);

    int ldis = FindLevel(ances, node1, 0);
    int rdis = FindLevel(ances, node2, 0);

    return (ldis + rdis);
}

int main()
{
    node *root = BinaryTree();

    int a, b;
    cin >> a >> b;

    cout << "Shortest distance between " << a << " and " << b << " : ";
    cout << Shortest(root, a, b) << endl;

    return 0;
}