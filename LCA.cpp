#include <iostream>
using namespace std;

// LCA: find Lowest Common Ancestor of 'a' and 'b': assuming a and b are present in tree.

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
    // base case:
    if (root == NULL)
    {
        return NULL;
    }

    if ((root)->data == a or (root)->data == b)
    {
        return root;
    }

    node *leftSide = LCA(root->left, a, b);
    node *rightSide = LCA(root->right, a, b);

    if (leftSide != NULL and rightSide != NULL)
    {
        return root;
    }

    if (rightSide != NULL)
    {
        return rightSide;
    }
    return leftSide;
}

int main()
{
    node *root = BinaryTree();
    int a, b;
    cin >> a >> b;

    cout << "LCA of " << a << " and " << b << ": " << endl;
    node *ans = LCA(root, a, b);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "does not exist!" << endl;
    }

    return 0;
}