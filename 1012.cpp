// 유기농 배추 : DFS

#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int a[50][50];
int m, n, k;
int result;
int dist[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void dfs(int x, int y) {
	if (a[x][y] == 0) return;

	a[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int dx = x + dist[i][0];
		int dy = y + dist[i][1];
		if (dx >= 0 && dx < m && dy >= 0 && dy < n && a[dx][dy] == 1) {
			dfs(dx, dy);
		}
	}
}

int main()
{
	int tc;
	cin >> tc;

	for (int t = 0;t < tc;++t) {
		cin >> m >> n >> k;
		memset(a, 0, sizeof(a));

		result = 0;
		vector<pair<int,int>> checked;
		for (int i = 0;i < k;++i) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
			checked.push_back(make_pair(x, y));
		}

		for (int i = 0;i < checked.size();i++) {
			int x = checked[i].first;
			int y = checked[i].second;
			if (a[x][y] == 1) {
				dfs(x, y);
				result += 1;
			}
		}
		cout << result << endl;
	}
	return 0;
}