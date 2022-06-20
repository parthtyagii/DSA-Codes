#include <iostream>
#include <queue>
#include <iomanip>
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

node *BuildTree(int *arr, int s, int e)
{
    // base case:
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    node *root = new node(arr[mid]);

    (root)->left = BuildTree(arr, s, mid - 1);
    (root)->right = BuildTree(arr, mid + 1, e);

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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    node *root = BuildTree(arr, 0, n - 1);
    BFS(root);

    return 0;
}