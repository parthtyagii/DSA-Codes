#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long ans = 1;
	long long a, b, c;
	cin >> a >> b >> c;

	while (b > 0)
	{
		if ((b & 1) == 1)
		{
			ans = (ans * a) % c;
		}
		a = (a * a) % c;
		b = (b >> 1);
	}

	cout << ans << endl;

	return 0;
}