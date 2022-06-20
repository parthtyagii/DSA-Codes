#include <iostream>
#include <queue>
using namespace std;

// Deletion in BST: O(height)

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

node *DELETION(node *root, int key)
{
    // base case:
    if (root == NULL)
    {
        return NULL;
    }

    if (key < (root)->data)
    {
        (root)->left = DELETION((root)->left, key);
        return root;
    }
    else if (key == (root)->data)
    {
        // case 1: no child.
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2: only one child.
        if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL and root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // case 3: two child.
        if (root->right != NULL and root->left != NULL)
        {
            // we choose root predecessor or successor to replace root node.
            // here we taking root successor. (in-order traversal)
            node *replace = root->right;

            while (replace->left != NULL)
            {
                replace = replace->left;
            }

            root->data = replace->data;
            root->right = DELETION(root->right, replace->data);

            return root;
        }
    }
    else
    {
        (root)->right = DELETION(root->right, key);
        return root;
    }
}

int main()
{
    node *root = BuildTree();

    BFS(root);

    int key;
    cin >> key;

    root = DELETION(root, key);
    BFS(root);

    return 0;
}