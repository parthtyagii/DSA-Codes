#include <iostream>
using namespace std;

// All the nodes at diatance 'k' from target node:

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


// Print nodes at k distance from root node:
void subTreeNodes(node *root, int k)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << (root)->data << " ";
        return;
    }

    subTreeNodes((root)->left, k - 1);
    subTreeNodes((root)->right, k - 1);
}

int nodesAtK(node *root, node *target, int k)
{
    // base case:
    if (root == NULL)
    {
        return -1;
    }

    // if root node is target node:
    if (root == target)
    {
        subTreeNodes(root,k);
        return 0;
    }

    // otherwise, we will check in left and right sub-tree: '-1' means target is not present in left sub-tree.
    // we are returning distance from target node:
    int dl = nodesAtK((root)->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << (root)->data << " ";
        }
        else
        {
            subTreeNodes((root)->right, k - 2 - dl);
        }

        return (dl + 1);
    }

    int dr = nodesAtK((root)->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout<<(root)->data<<" ";
        }
        else
        {
            subTreeNodes((root)->left, k - 2 - dr);
        }

        return (dr + 1);
    }

    // if target is not present in right and left sub-tree:
    return -1;
}

int main()
{
    node *root = BinaryTree();
    int k = 2;
    node *target = (root)->left->left;

    nodesAtK(root, target, k);

    return 0;
}

