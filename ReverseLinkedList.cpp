#include <iostream>
using namespace std;

// Reverse Linked List: iterative and Recursive approach
// iterative: O(N) time and O(1) space...
// recursive: O(N) time and O(N) space...

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

    return cin;
}

ostream &operator<<(ostream &cout, node *head)
{
    printList(head);

    return cout;
}

// iterative approach:
void reverseList(node *&head)
{

    node *prev = NULL;
    node *curr = head;
    node *n;

    while (curr != NULL)
    {

        n = (curr)->next;

        (curr)->next = prev;

        prev = curr;
        curr = n;
    }

    head = prev;

    return;
}

node *RecursiveReverseList(node *head)
{
    // base case:
    if (head == NULL or (head)->next)
    {
        return head;
    }

    node *shead = RecursiveReverseList((head)->next);

    node *temp = head;

    // while ((temp)->next != NULL)
    // {
    //     temp = (temp)->next;
    // }

    // more efficient approach:
    temp = (head)->next;

    (head)->next = NULL;
    (temp)->next = head;

    return shead;
}

int main()
{
    node *head = NULL;
    cin >> head;
    cout << "actual list:" << endl;
    cout << head;

    cout << "iterative approach:" << endl;
    reverseList(head);
    cout << head;

    cout << "recursive approach:" << endl;
    RecursiveReverseList(head);
    cout << head;

    return 0;
}