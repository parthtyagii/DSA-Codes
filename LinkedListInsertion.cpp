#include <iostream>
using namespace std;

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

// insertAtHead: every new insertion becomes the head of the linked list.
void insertAtHead(node *&head, int d) // we have to pass head address as reference becoz we also want it to point to new data(new head).
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

// insertAtTail: every new insertion becomes the tail node of the linked list.
void insertAtTail(node *&head, int d) // passing head as reference: in case head pointer is pointing at null.
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

void insertAtMiddle(node *&head, int d, int pos) // passing head as reference: in case of pos = 0, our head of list will be changed.
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

int main()
{
    node *head = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertAtHead(head, x);
        // insertAtHead(head, 2);
        // insertAtHead(head, 1);
        // insertAtHead(head, 0);
    }

    printList(head);
    cout << "after inserting middle element: " << endl;

    insertAtMiddle(head, 3, 3);
    insertAtMiddle(head, 10, 5);

    printList(head);

    return 0;
}
