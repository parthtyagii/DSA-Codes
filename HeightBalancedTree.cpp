#include <iostream>
using namespace std;

// Height Balanced Tree: (optimized approach)

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

class Pair
{
public:
    int height;
    bool balance;
};

Pair checkBalance(node *root)
{
    Pair currNode;
    // base case:
    if (root == NULL)
    {
        currNode.balance = true;
        currNode.height = 0;
        return currNode;
    }

    // post-order traversal:
    Pair left = checkBalance((root)->left);
    Pair right = checkBalance((root)->right);

    currNode.height = max(left.height, right.height) + 1;

    // abs(x) = |x|: <cmath> header file
    if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
    {
        currNode.balance = true;
    }
    else
    {
        currNode.balance = false;
    }

    return currNode;
}

int main()
{
    node *root = BinaryTree();

    Pair check = checkBalance(root);
    if (check.balance)
    {
        cout << "Tree is balanced." << endl;
    }
    else
    {
        cout << "Tree is not balanced." << endl;
    }

    return 0;
}