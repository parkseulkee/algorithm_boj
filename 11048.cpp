// 이동하기 : dp

#include <iostream>
using namespace std;

int d[1001][1001];

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			d[i][j] += max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[n][m] << endl;
	return 0;
}