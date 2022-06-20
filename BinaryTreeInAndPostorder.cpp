#include <iostream>
using namespace std;

// Binary Tree (traversal):

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

void PrintPre(node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // otherwise, print root data followed by subtrees.
    cout << root->data << " ";

    PrintPre((root)->left);
    PrintPre((root)->right);

    return;
}

void PrintIn(node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // otherwise, print root data followed by subtrees.
    PrintIn((root)->left);

    cout << root->data << " ";

    PrintIn((root)->right);

    return;
}

void PrintPost(node *root)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // otherwise, print root data followed by subtrees.

    PrintPost((root)->left);
    PrintPost((root)->right);

    cout << root->data << " ";

    return;
}

int main()
{
    node *root = BinaryTree();

    PrintPre(root);
    cout << endl;

    PrintIn(root);
    cout << endl;

    PrintPost(root);
    cout << endl;

    return 0;
}