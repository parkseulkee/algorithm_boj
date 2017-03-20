// 바이러스 : 플로이드-와샬 알고리즘

#include <iostream>
using namespace std;

int n;
int c[101][101];
int d[101];

void dfs(int x) {
	for (int i = 2;i <= n;i++) {
		if (c[x][i] == 1) {
			c[x][i] = c[i][x] = 0;
			d[i] = 1;
			dfs(i);
		}
	}
}

int main()
{
	int m, result = 0;
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;

		c[x][y] = c[y][x] = 1;
	}

	dfs(1);

	for (int i = 1;i <= n;i++) {
		result += d[i];
	}

	cout << result << endl;

	return 0;
}