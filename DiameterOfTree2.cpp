#include <iostream>
using namespace std;

// Diameter of Tree: optimized approach...

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
    int diameter;
};

Pair Diameter(node *root)
{
    Pair currNode;
    // base case:
    if (root == NULL)
    {
        currNode.height = 0;
        currNode.diameter = 0;
        return currNode;
    }

    // ohterwise...(post-order traversal)
    Pair lside = Diameter((root)->left);
    Pair rside = Diameter((root)->right);

    (currNode).height = max(lside.height, rside.height) + 1;
    (currNode).diameter = max((lside.height + rside.height), max(lside.diameter, rside.diameter));

    return currNode;
}

int main()
{
    node *root = BinaryTree();

    Pair maxDiameter = Diameter(root);

    cout << maxDiameter.height << endl;
    cout << maxDiameter.diameter << endl;

    return 0;
}

