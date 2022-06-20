#include <iostream>
using namespace std;

// Sum Replacement(problem):

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

int SumReplace(node *root)
{
    // base case:
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return (root)->data;
    }

    int temp = (root)->data;
    int ls = SumReplace((root)->left);
    int rs = SumReplace((root)->right);

    (root)->data = ls + rs;
    return ((root)->data + temp);
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
    cout << endl;

    SumReplace(root);
    PrintTree(root);

    return 0;
}