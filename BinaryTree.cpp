#include <iostream>
using namespace std;

// Binary Tree (implementation): using recursion....pre-order technique.

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

void PrintTree(node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // otherwise, print root data followed by subtrees.
    cout << root->data << " ";

    PrintTree((root)->left);
    PrintTree((root)->right);

    return;
}

int main()
{
    node *root = BinaryTree();
    PrintTree(root);

    return 0;
}