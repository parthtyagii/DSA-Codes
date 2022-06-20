#include <iostream>
#include <string>
using namespace std;

// Rehashing:

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

    void Rehash()
    {
        node<T> **oldtable = table;
        int oldtablesize = table_size;
        table_size = 2 * table_size; // atleast double size.....(prime number recommended)
        table = new node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        for (int i = 0; i < oldtablesize; i++)
        {
            node<T> *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }

        delete[] oldtable;
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

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "-> ";
            node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void insert(string key, T value)
    {
        // find indx....
        int idx = hashfn(key);

        node<T> *n = new node<T>(key, value);

        // inserting at head of the the linked list...
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        // rehash: .....
        float load_factor = current_size / (1.0 * table_size);

        if (load_factor > 0.7)
        {
            Rehash();
        }
    }
};

int main()
{
    Hashtable<int> first;
    first.insert("Pizza", 233);
    first.insert("Burger", 422);
    first.insert("Noodles", 99);
    first.insert("Fries", 70);
    first.insert("Apple", 988);
    first.insert("Orange", 679);
    // first.insert("Banana", 340);

    first.print();

    return 0;
}