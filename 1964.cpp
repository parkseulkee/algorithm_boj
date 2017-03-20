#include <iostream>
using namespace std;

int d[10000000];

int main()
{
	int n;
	cin >> n;

	d[1] = 5;

	for (int i = 2; i <= n; i++){
		d[i] = d[i - 1] + (i + 1) + 2 * i;
		d[i] %= 45678;
	}

	cout << d[n] << endl;
	return 0;
}