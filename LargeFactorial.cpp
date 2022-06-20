#include <iostream>
using namespace std;

// Factorial of large numbers:

class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode(int d)
    {
        data = d;
        prev = NULL;
    }
};

void Print(ListNode *tail)
{
    if (tail == NULL)
    {
        return;
    }
    Print(tail->prev);
    cout << tail->data;
}

void Multiply(ListNode *tail, int i)
{
    ListNode *temp = tail;
    ListNode *prevNode = tail;
    int carry = 0;
    while (temp != NULL)
    {
        int x = (temp->data * i) + carry;
        temp->data = x % 10;
        carry = x / 10;
        prevNode = temp;
        temp = temp->prev;
    }
    while (carry != 0)
    {
        prevNode->prev = new ListNode(carry % 10);
        carry /= 10;
        prevNode = prevNode->prev;
    }
}

void FindFactorial(int n)
{
    ListNode *tail = new ListNode(1);
    for (int i = 2; i <= n; i++)
    {
        Multiply(tail, i);
    }
    Print(tail);
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    FindFactorial(n);

    return 0;
}