#include <iostream>
using namespace std;

// Floyd's Cycle: if there is any cycle present in the linked list.

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

node *mergeSort(node *head)
{
    // base case:
    if (head == NULL or (head)->next == NULL)
    {
        return head;
    }

    node *a = head;
    node *mid = midPoint(head);
    node *b = (mid)->next;

    (mid)->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node *c = mergeList(a, b);

    return c;
}

bool ifAnyCycle(node *head)
{
    if (head == NULL or (head)->next == NULL)
    {
        return false;
    }

    node *fast = head;
    node *slow = head;

    while (fast != NULL and (fast)->next != NULL)
    {
        fast = (fast)->next->next;
        slow = (slow)->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

void makeCycle(node *head)
{
    node *a = head->next->next;
    while (head->next != NULL)
    {
        head = head->next;
    }

    (head)->next = a;

    return;
}

void deleteCycle(node *head)
{
    if (head == NULL or (head)->next == NULL)
    {
        return;
    }

    node *start = head;
    node *fast = head;
    node *slow = head;

    while (fast != NULL and (fast)->next != NULL)
    {
        fast = (fast)->next->next;
        slow = (slow)->next;

        if (fast == slow)
        {
            slow = start;
            break;
        }
    }

    while ((slow)->next != (fast)->next)
    {
        slow = (slow)->next;
        fast = (fast)->next;
    }

    (fast)->next = NULL;

    return;
}

int main()
{
    node *head = NULL;
    cin >> head;

    makeCycle(head); // this fuction is made for a particular case only.

    bool check = ifAnyCycle(head);
    if (check)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    deleteCycle(head);

    bool check2 = ifAnyCycle(head);
    if (check2)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    cout << head << endl;

    return 0;
}
