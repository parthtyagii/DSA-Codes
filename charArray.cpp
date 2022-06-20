#include <iostream>
using namespace std;

// Introduction: char array

int main()
{
     int arr[] = {1, 2, 3};
     char a[] = {'p', 'a', 'r', 't', 'h', '\0'};
     cout << arr << endl
          << a << endl;

     char b[100];
     cin >> b;
     cout << b << endl;

     char c[] = "parth tyagi";
     cout << c << endl;

     char d[] = {'t', 'y', 'a', 'g', 'i'}; // here '\0' is important.
     cout << d << endl;

     cout << sizeof(c) << endl
          << c << endl
          << sizeof(d) << endl;

     return 0;
}
