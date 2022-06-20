#include <iostream>
using namespace std;

// overloading operator: >> and <<

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

node *taking_input()
{

    node *head = NULL;
    int d;
    cin >> d;

    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }

    return head;
}

istream &operator>>(istream &cin, node *&head)
{
    head = taking_input();

    return cin; // Cascading of operators...
}

ostream &operator<<(ostream &cout, node *head)
{
    printList(head);

    return cout; // Cascading of operators...
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    cin >> head1 >> head2; // Cascading of operators...

    cout << head1 << head2;

    return 0;
}