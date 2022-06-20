#include <iostream>
using namespace std;

// Count number of nodes And Sum of all nodes: pre-order..

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

int Count(node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    return (Count((root)->left) + Count((root)->right) + 1);
}

int SumOfNodes(node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    return (SumOfNodes((root)->left) + SumOfNodes((root)->right) + (root)->data);
}

int main()
{
    node *root = BinaryTree();
    // PrintTree(root);

    cout << Count(root) << endl;

    cout << SumOfNodes(root) << endl;

    return 0;
}
