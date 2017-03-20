// DFS와 BFS : DFS,BFS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n, m, v;
int a[1001][1001];
bool check[1001] = { false, };

void dfs(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 1;i <= n;i++) {
		if (a[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

void bfs() {
	for (int i = 1;i <= n;i++) check[i] = false;
	cout << endl;

	queue<int> q;
	check[v] = true; q.push(v);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << " ";
		for (int i = 1;i <= n;i++) {
			if (a[x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0;i < m;i++) {
		int s, e;
		cin >> s >> e;
		a[s][e] = a[e][s] = 1;
	}

	dfs(v);
	bfs();

	return 0;
}