#include <iostream>
using namespace std;

// Merging two sorted linked list:

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

    temp = (head)->next;

    (head)->next = NULL;
    (temp)->next = head;

    return shead;
}

node *midPoint(node *head)
{
    if (head == NULL or (*head).next == NULL)
    {
        return head;
    }

    node *fast = (head)->next;
    node *slow = head;

    while (fast != NULL and (*fast).next != NULL)
    {

        fast = (fast)->next->next;
        slow = (slow)->next;
    }

    return slow;
}

// Recursive approach: we are making new pointers not making new list.
node *mergeList(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *p;

    if (head1->data <= head2->data)
    {
        p = head1;
        p->next = mergeList(head1->next, head2);
    }
    else
    {
        p = head2;
        p->next = mergeList(head1, head2->next);
    }

    return p;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    cin >> head1 >> head2;

    node *merged = mergeList(head1, head2);

    cout << merged << endl;

    return 0;
}