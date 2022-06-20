#include <iostream>
using namespace std;

void increment(int *z)
{
    *z = *z + 1;
}

int main()
{
    // Address Operator: Address is stored in hexadecimal form.
    int y = 10;
    cout << &y << endl;

    char ch = 'a';
    cout << &ch << endl;         // Cannot use '&' to print address of character data type.
    cout << (void *)&ch << endl; // we can use Explicit type casting.

    // Pointers:
    int x = 10;
    int z = 99;
    int *xptr = 0;                        // <---: NULL pointer
    xptr = &x;                            // data-type of pointer should be = data-type of variable.
    cout << xptr << " " << *xptr << endl; // Space occupied to store address of different data-type is same.
                                          // Eg: for integer pointer will point at first boxe of int memory.
    int q = 1;
    int w = 2;
    int *p1 = &q;
    int *p2 = &w;
    cout << (p1 - p2) << endl; // Difference of addresses will give number of elements between them.

    int arr[10];                                                              // an array is also a pointer itself.
    cout << arr << " " << arr + 1 << " " << (arr + 2) << " " << &arr << endl; // &arr will return address of '0th' index.
                                                                              // do not use & operator for array

    cout<<sizeof(p2)<<" "<<sizeof(arr)<<" "<<p2<<" "<<p2++<<" "<<endl;
                                                                        

    xptr = &z;
    cout << xptr << endl; // Pointer can be re-assigned.

    // Deference Operator: ( * )
    cout << *xptr << endl;
    cout << &(*xptr) << " " << (*xptr) + 1 << " " << *(xptr + 1) << endl;

    int **xxptr = &xptr; // we point a pointer using another pointer of data-type of first pointer.
    cout << xxptr << " " << *xxptr << " " << **xxptr << endl;

    // Pass by reference using pointer:
    increment(&z);
    cout << z << endl;

    return 0;
}
