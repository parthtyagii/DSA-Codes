#include <iostream>
using namespace std;

// Returning local and dynamic arrays:

int *func()
{
    int *a = new int[3]{13,12,55};
    // a[0]=11;
    // a[1]=12;
    cout << a << endl;
    cout << a[0] << endl;

    return a;
}

int main()
{
    int *b = func();
    cout << b << endl;
    cout << b[2] << endl;

    delete[] b;

    return 0;
}


