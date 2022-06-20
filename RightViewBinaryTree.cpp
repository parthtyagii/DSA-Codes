#include <iostream>
using namespace std;

// Right View: right most element of each level.

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

void rightView(node *root, int level, int &maxlevel)
{
    // base case:
    if (root == NULL)
    {
        return;
    }

    // we are maintaining current level and max-level till now:
    if (maxlevel < level)
    {
        cout << (root)->data << " ";
        maxlevel = level;
    }

    // otherwise, go right and left side:
    rightView((root)->right, level + 1, maxlevel);
    rightView((root)->left, level + 1, maxlevel);
}

int main()
{
    node *root = BinaryTree();

    int level = 0;
    int maxlevel = -1;
    rightView(root, level, maxlevel);

    return 0;
}