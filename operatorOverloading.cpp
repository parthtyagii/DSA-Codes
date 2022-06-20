#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

// Operator Overloading:

class complex
{

    int real;
    int img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }

    void realcom(int r)
    {
        real = r;
    }

    void imgcom(int i)
    {
        img = i;
    }

    void print()
    {
        if (img > 0)
        {
            cout << real << " + " << img << "i" << endl;
        }
        else
        {
            cout << real << " - " << (-1) * img << "i" << endl;
        }
    }

    void operator+(complex &x)
    {
        real += x.real;
        img += x.img;
    }

    void operator!()
    {
        img = (-1) * img;
    }

    void operator[](string s)
    {
        cout << s << endl;
    }
};

void operator>>(istream &cin, complex &x)
{
    int r, i;
    cin >> r >> i;

    x.realcom(r);
    x.imgcom(i);
}

void operator<<(ostream &cout, complex &x)
{
    x.print();
}

int main()
{
    complex o1;
    o1.realcom(2);
    o1.imgcom(4);

    complex o2;
    o2.realcom(3);
    o2.imgcom(5);

    o1 + o2;
    o1.print();

    !o2;
    o2.print();

    complex o3; // --> Binary operator
    cin >> o3;
    cout << o3;

    o3["Parth Tyagi"]; // --> Binary operator

    return 0;
}
