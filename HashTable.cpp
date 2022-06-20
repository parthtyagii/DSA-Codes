#include <iostream>
using namespace std;

// Hashtable: implementation...
// ---> insertion
// ---> deletion
// ---> searching

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;

    node(string key, T val)
    {
        (this)->key = key;
        value = val;
        next = NULL;
    }

    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
    node<T> **table;
    int current_size;
    int table_size;

    int hashfn(string key)
    {
        int idx = 0;
        int p = 1;

        for (int i = 0; i < key.length(); i++)
        {
            idx = idx + (key[i] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

public:
    Hashtable(int ts = 7)
    {
        table_size = ts;
        table = new node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        // fing indx....
        int idx = hashfn(key);

        node<T> *n = new node<T>(key, value);

        // inserting at head of the the linked list...
        n->next = table[idx];
        table[idx] = n;

        // rehash: .....
    }
};

int main()
{

    return 0;
}