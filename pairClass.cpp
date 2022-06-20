#include <iostream>
using namespace std;

// Pair Class:

int main()
{
    pair<int, string> p1;
    p1.first = 10;
    p1.second = 'A';
    cout << p1.first << endl;
    cout << p1.second << endl;

    // make pair function:
    pair<int, int> p2 = make_pair(100, 1001);
    cout << p2.first << endl;
    cout << p2.second << endl;

    string a, b;
    cin >> a >> b;
    pair<string, string> p3 = make_pair(a, b);
    cout << p3.first << endl;
    cout << p3.second << endl;

    // array of pairs:
    pair<int, int> p4[2];
    p4[0] = make_pair(12, 21);
    p4[1] = make_pair(13, 31);
    cout << p4[0].first << endl;
    cout << p4[1].second << endl;

    // pair of pair:
    pair<pair<int, string>, string> car;
    car.first = make_pair(2122, "DEL");
    car.second = "Ferrari";
    cout << car.first.first << " " << car.first.second << " ";
    cout << car.second << endl;

    return 0;
}
