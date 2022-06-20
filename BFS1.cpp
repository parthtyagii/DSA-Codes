#include <iostream>
#include <queue>
using namespace std;

// BFS: breadth first search(or traversal)..
// --> using a Queue..

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

void BFS(node *root)
{
    // include a queue: and add the root data.
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        cout << (f)->data << " ";
        q.pop();

        // adding current roots left and right child in the queue:
        if ((f)->left)
        {
            q.push((f)->left);
        }

        if ((f)->right)
        {
            q.push((f)->right);
        }
    }

    return;
}

int main()
{
    node *root = BinaryTree();
    BFS(root);

    return 0;
}