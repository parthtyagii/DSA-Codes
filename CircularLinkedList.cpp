#include <iostream>
using namespace std;

// Circular Linked List: insertion and deletion.

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

void insertAtHead(node *&head, int data)
{

    node *n = new node(data);
    (n)->next = head;

    node *temp = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        (n)->next = n;
    }

    head = n;

    return;
}

void printList(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
    return;
}

node *checkNode(node *head, int d)
{

    node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == d)
        {
            return temp;
        }
        temp = temp->next;
    }

    if (temp->data == d)
    {
        return temp;
    }

    return NULL;
}

void deleteNode(node *&head, int data)
{
    node *del = checkNode(head, data);
    if (del == NULL)
    {
        return;
    }

    // if del is head...
    if (del == head)
    {
        head = head->next;
    }

    // if del is not head...
    node *temp = head;
    while (temp->next != del)
    {
        temp = (temp)->next;
    }

    temp->next = del->next;
    delete del;

    return;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    printList(head);

    int key;
    cin >> key;
    deleteNode(head, key);
    printList(head);

    return 0;
}