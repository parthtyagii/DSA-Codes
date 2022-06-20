#include <iostream>
#include <queue>
using namespace std;

// Building a BST:

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

int main()
{
    node *root = BuildTree();
    BFS(root);

    return 0;
}