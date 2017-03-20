#include <iostream>
using namespace std;

int c[1001];
int d[1001];

int main()
{
	int n, max = 0;

	cin >> n;

	for (int i = 1;i <= n;i++) cin >> c[i];

	for (int i = 1;i <= n;i++) {
		if (c[i] < c[i + 1]) {
			d[i] = d[i - 1] + (c[i + 1] - c[i]);
		}
		max = max > d[i - 1] ? max : d[i - 1];
	}
	cout << max << endl;
	return 0;
}