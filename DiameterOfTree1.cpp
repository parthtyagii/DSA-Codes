#include <iostream>
using namespace std;

// Diameter of Binary Tree:

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

int height(node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    int ls = height((root)->left);
    int rs = height((root)->right);

    return (max(ls, rs) + 1);
}

int Diameter(node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }

    int h1 = height((root)->left);
    int h2 = height((root)->right);

    int leftTree = Diameter((root)->left);
    int rightTree = Diameter((root)->right);

    return max((h1 + h2), max(leftTree, rightTree));
}

int main()
{
    node *root = BinaryTree();

    cout << Diameter(root) << endl;

    return 0;
}