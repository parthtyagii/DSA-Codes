#include <iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printNum(int n)
{
    if (n == 0)
    {
        return;
    }

    printNum(n / 10);

    int alpha = n % 10;
    cout << words[alpha] << " ";
}

int main()
{
    int n;
    cin >> n;

    printNum(n);

    return 0;
}