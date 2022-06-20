#include <iostream>
using namespace std;

// Searching: linear search

class node
{

public:
    int data;
    node *next;

    // constructor:
    node(int data)
    {
        (this)->data = data;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *n = new node(d);
    (n)->next = head;
    head = n;
}

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *tail = head;
    while ((tail)->next != NULL)
    {
        tail = (tail)->next;
    }

    (tail)->next = new node(d);

    return;
}

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = (head)->next;
    }
    return count;
}

void insertAtMiddle(node *&head, int d, int pos) 
{
    if (pos == 0 or head == NULL)
    {
        insertAtHead(head, d);
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(head, d);
        return;
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= (pos - 1))
        {
            temp = (temp)->next;
            jump++;
        }

        node *n = new node(d);
        (n)->next = (temp)->next;
        (temp)->next = n;
    }
}

void printList(node *head)
{

    while (head != NULL)
    {
        cout << (head)->data << " ";
        head = (*head).next;
    }
    cout << endl;
}

bool Search(node *head, int key)
{
    while (head != NULL)
    {
        if ((*head).data == key)
        {
            return true;
        }

        head = (head)->next;
    }

    return false;
}

bool SearchRecursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if ((head)->data == key)
    {
        return true;
    }
    else
    {
        return SearchRecursive((head)->next, key);
    }
}

int main()
{
    node *head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    int k;
    cin >> k;
    
    // if (Search(head, k))
    // {
    //     cout << "key found!" << endl;
    // }
    // else
    // {
    //     cout << "key not found." << endl;
    // }

    if (SearchRecursive(head, k))
    {
        cout << "key found!" << endl;
    }
    else
    {
        cout << "key not found." << endl;
    }

    return 0;
}