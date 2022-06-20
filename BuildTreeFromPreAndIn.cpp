#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

// Build a Tree: using pre and in-order inputs

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

            cout << setw(2) << (f)->data << " ";
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

int i = 0; // we can also use static variable inside.
node *BuildTree(int *pre, int *in, int s, int e)
{
    // base case:
    if (s > e)
    {
        return NULL;
    }

    node *root = new node(pre[i]);

    int idx = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            idx = j;
            break;
        }
    }

    i++;
    (root)->left = BuildTree(pre, in, s, idx - 1);
    (root)->right = BuildTree(pre, in, idx + 1, e);

    return root;
}

int main()
{
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int in[] = {3, 2, 8, 4, 1, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);

    node *root = BuildTree(pre, in, 0, n - 1);
    BFS(root);

    return 0;
}