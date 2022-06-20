#include <iostream>
#include <queue>
using namespace std;

// Convert BST to Linked List: flatten BST...

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

class Pair
{
public:
    node *head;
    node *tail;
};

Pair CONVERT(node *root)
{
    Pair temp;
    // base case:
    if (root == NULL)
    {
        temp.head = temp.tail = NULL;
        return temp;
    }

    // case 1: leaf node.
    if (root->left == NULL and root->right == NULL)
    {
        temp.head = temp.tail = root;
        return temp;
    }

    // case 2: only one sub-tree.
    if (root->left != NULL and root->right == NULL)
    {
        Pair leftTemp = CONVERT(root->left);
        leftTemp.tail->right = root;

        temp.head = leftTemp.head;
        temp.tail = root;

        return temp;
    }

    if (root->left == NULL and root->right != NULL)
    {
        Pair rightTemp = CONVERT(root->right);
        root->right = rightTemp.head;

        temp.head = root;
        temp.tail = rightTemp.tail;

        return temp;
    }

    // case 3: both sub-tree.
    Pair leftTemp = CONVERT(root->left);
    Pair rightTemp = CONVERT(root->right);

    leftTemp.tail->right = root;
    root->right = rightTemp.head;

    temp.head = leftTemp.head;
    temp.tail = rightTemp.tail;

    return temp;
}

int main()
{
    node *root = BuildTree();
    BFS(root);

    Pair LinkedList = CONVERT(root);

    while (LinkedList.head != NULL)
    {
        cout << LinkedList.head->data << "-->";
        LinkedList.head = LinkedList.head->right;
    }

    return 0;
}