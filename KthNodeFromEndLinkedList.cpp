#include <iostream>
using namespace std;

// Reverse Linked List: iterative and Recursive approach

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
        insertAtTail(head, d);
        cin >> d;
    }

    return head;
}

istream &operator>>(istream &cin, node *&head)
{
    head = taking_input();

    return cin;
}

ostream &operator<<(ostream &cout, node *head)
{
    printList(head);

    return cout;
}

node *fromEnd(node *head, int key)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    node *fast = head;
    node *slow = head;
    while (key > 0)
    {
        fast = (fast)->next;
        key--;
    }

    while (fast != NULL)
    {
        fast = (fast)->next;
        slow = (slow)->next;
    }

    return slow;
}

int main()
{
    node *head = NULL;
    cin >> head;
    int key;
    cin >> key;

    node *kFromEnd = fromEnd(head, key);

    cout << (kFromEnd)->data << endl;

    return 0;
}
