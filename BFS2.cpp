#include <iostream>
#include <queue>
using namespace std;

// BFS: breadth first search(or traversal)..
// Printing each level in new line.

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
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();

        if (f == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << (f)->data << " ";
            q.pop();

            if ((f)->left)
            {
                q.push((f)->left);
            }

            if ((f)->right)
            {
                q.push((f)->right);
            }
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