#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class car
{

    int price;

public:
    char *name;
    int model;

    car() : model(50)
    {
        name = NULL;
    }

    car(char n[], int p, int m = 50) : price(p), model(m)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void get() const
    {
        cout << name << endl;
        cout << model << endl;
        cout << price << endl;
    }

    car(car &x)
    {
        // for Deep Copy:
        price = x.price;
        model = x.model;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }

    void operator=(car x)
    {
        // for Deep Copy:
        price = x.price;
        model = x.model;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }

    ~car()
    {
        cout << "destructor for " << name << endl;
        if (name != NULL)
        {
            delete[] name;
        }
    }
};

int main()
{
    car o1("BMW", 100);
    // car o2(o1); // copy constructor will be called.
    car o2;
    o2 = o1; // copy assignment operator will be called.

    o2.model = 2020;
    o2.name[0] = 'A';

    o1.get();
    o2.get();

    car *o3 = new car("tesla", 300, 3030);
    (*o3).get();

    car *o4 = new car("maruti", 300, 3030);
    (*o4).get();

    delete o4;
    delete o3;

    return 0;
}
