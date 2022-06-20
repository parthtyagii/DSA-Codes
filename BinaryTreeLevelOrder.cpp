#include <iostream>
using namespace std;

// Binary Tree: level order printing using recursion.
// --> first we will calculate maximum height of the binary tree.
// --> then we wil print each level.
// --> O(N^2) complexity.

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

void PrintTree(node *root, int k)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    if (k == 1)
    {
        cout << (root)->data << " ";
        return;
    }

    PrintTree((root)->left, k - 1);
    PrintTree((root)->right, k - 1);

    return;
}

void PrintAllLevel(node *root)
{
    int k = height(root);

    for (int i = 1; i <= k; i++)
    {
        PrintTree(root, i);
        cout << endl;
    }
}

int main()
{
    node *root = BinaryTree();
    PrintAllLevel(root);

    return 0;
}