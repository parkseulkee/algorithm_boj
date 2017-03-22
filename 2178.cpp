// 미로탐색 : BFS

#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int a[101][101];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

struct element{
	int x, y, l;
};

int dfs() {
	queue<element> q;
	element e;
	e.x = 1;
	e.y = 1;
	e.l = 1;
	q.push(e);

	a[1][1] = 0;
	while (!q.empty()) {
		e = q.front();
		q.pop();
		if (e.x == n && e.y == m) break;

		for (int i = 0;i < 4;i++) {
			int dx = e.x + dir[i][0];
			int dy = e.y + dir[i][1];
			if (dx > 0 && dx <= n && dy > 0 && dy <= m && a[dx][dy] == 1) {
				element el;
				el.x = dx;
				el.y = dy;
				el.l = e.l + 1;
				q.push(el);
				a[el.x][el.y] = 0;
			}
		}
	}
	return e.l;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	printf("%d\n", dfs());
	return 0;
}