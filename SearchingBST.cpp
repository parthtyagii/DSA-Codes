#include <iostream>
#include <queue>
using namespace std;

// Searching BST: O(height)

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

node *InsertInBST(node *root, int d)
{
    // base case:
    if (root == NULL)
    {
        return new node(d);
    }

    if (d <= (root)->data)
    {
        (root)->left = InsertInBST((root)->left, d);
    }
    else
    {
        (root)->right = InsertInBST((root)->right, d);
    }

    return root;
}

node *BuildTree()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        root = InsertInBST(root, d);
        cin >> d;
    }

    return root;
}

bool SEARCH(node *root, int key)
{
    // base case:
    if (root == NULL)
    {
        return NULL;
    }

    if ((root)->data == key)
    {
        return true;
    }

    if (key < (root)->data)
    {
        return SEARCH(root->left, key);
    }
    else
    {
        return SEARCH(root->right, key);
    }
}

int main()
{
    node *root = BuildTree();

    int key;
    cin >> key;

    if (SEARCH(root, key))
    {
        cout << "node found!!" << endl;
    }
    else
    {
        cout << "node not found!!" << endl;
    }

    return 0;
}