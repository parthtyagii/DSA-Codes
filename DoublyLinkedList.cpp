#include <iostream>
using namespace std;

// Doubly Linked List: two pointers instead of one in singly linked list.

class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
    node(int data)
    {
        (this)->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    (n)->next = head;
    (head)->prev = n;
    head = n;

    return;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *n = new node(data);
    (temp)->next = n;
    (n)->prev = temp;

    return;
}

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtMiddle(node *&head,int data,int pos)
{
    if (pos <= 0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (pos >= length(head))
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        node *temp = head;
        while (pos > 1)
        {
            temp = (temp)->next;
        }

        node *n = new node(data);
        node *agla = temp->next;

        temp->next = n;
        n->prev = temp;

        n->next = agla;
        agla->prev = n;

        return;
    }
}

void printList(node *head)
{
    if (head == NULL)
    {
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void buildList(node *&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertAtTail(head, d);
        cin>>d;
    }
    return;
}


int main()
{
    node *head = NULL;
    buildList(head);
    printList(head);

    return 0;
}