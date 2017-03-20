// 케빈 베이컨의 6단계 법칙 : 플로이드-와샬 알고리즘
#include <iostream>
#include <memory.h>
using namespace std;

int d[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	memset(d, n + 1, sizeof(d));

	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		d[x][y] = d[y][x] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int ans = -1;
	int who = -1;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			sum += d[i][j];
		}
		if (ans == -1 || sum < ans) {
			ans = sum;
			who = i;
		}
	}

	cout << who << endl;
	return 0;
}