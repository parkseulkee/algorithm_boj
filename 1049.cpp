#include <iostream>
#include <algorithm>
using namespace std;

int p[50];
int k[50];

int _min(int a, int b) {
	return a < b ? a : b;
}

int _min3(int a, int b, int c) {
	return _min(a, b) < c ? _min(a, b) : c;
}

int main()
{
	int n, m;
	int result;
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		cin >> p[i] >> k[i];
	}

	sort(p, p + m);
	sort(k, k + m);

	int r = n / 6;
	int rr = n % 6;

	if (rr == 0) {
		cout << _min(r*p[0], n*k[0]) << endl;
	}
	else {
		cout << _min3((r + 1)*p[0], r*p[0] + rr*k[0], n*k[0]) << endl;
	}

	return 0;
}