#include <iostream>
using namespace std;

// Queues: implementaion using linked list.

class node;

class Queue
{
    node *head;
    int cs;

public:
    Queue()
    {
        head = NULL;
        cs = 0;
    }

    void push(int d)
    {
        cs++;
        insertAtTail(head, d);
    }

    void pop()
    {
        cs--;
        Delete(head);
    }

    bool empty()
    {
        return cs == 0;
    }

    int front()
    {
        if (head != NULL)
        {
            return head->data;
        }
    }
};


// linked list nodes:
class node
{
public:
    node *next;
    friend class Queue;
    int data;

    node(int d)
    {
        data = d;
        next = NULL;
    }

    void insertAtTail(node *&head, int d)
    {
        if (head == NULL)
        {
            head = new node(d);
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
        }

        temp->next = new node(d);
        return;
    }

    void Delete(node *&head)
    {
        if (head != NULL)
        {
            node *n = head->next;
            delete head;
            head = n;
        }
    }
};

int main()
{
    Queue q;

    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    q.front();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}