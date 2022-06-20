#include <iostream>
#include <cstring>
using namespace std;

// Largest String:

int main()
{
    int n;
    cin >> n;

    char arr[1000];
    char b[1000];
    int lar = 0;
    int clar = 0;


    // cin.ignore(): can also be used...
    cin.get(); // consuming extra space...
    for (int i = 0; i < n; i++)
    {
        cin.getline(arr, 1000);

        clar = strlen(arr);
        if (clar > lar)
        {
            lar = clar;
            strcpy(b, arr); // We can also use loop to copy array.

            // int j;
            // for (j = 0; j < lar; j++)
            // {
            //     b[j] = arr[j];
            // }
            // b[j] = '\0';
        }
    }

    cout << "Largest String: " << b << endl;
    cout << "Length: " << lar;

    return 0;
}
