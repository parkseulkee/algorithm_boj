// 레드 블루 스패닝 트리

#include <iostream>
#include <algorithm>
using namespace std;

struct edge { int from;int to;int cost; };
struct edge edges[10000000];
int p[1001];

int find(int v) {
	if (p[v] == v) return v;
	else return p[v] = find(p[v]);
}

bool cmp1(struct edge a, struct edge b) { return a.cost > b.cost; }
bool cmp2(struct edge a, struct edge b) { return a.cost < b.cost; }

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	while (!(n == 0 && m == 0 && k == 0)) {
		char ch;
		int blue = 0, red = 0;
		for (int i = 1;i <= n;i++) p[i] = i;
		for (int i = 0;i < m;i++) {
			cin >> ch >> edges[i].from >> edges[i].to;
			if (ch == 'B') edges[i].cost = 1;
			else edges[i].cost = 0;
		}
		// blue 기준으로 정렬
		sort(edges, edges + m, cmp1);
		for (int i = 0;i < m;i++) {
			int v = find(edges[i].from);
			int u = find(edges[i].to);
			if (u != v) {
				blue += edges[i].cost;
				p[u] = v;
			}
		}
		for (int i = 1;i <= n;i++) p[i] = i;
		// red 기준으로 정렬
		sort(edges, edges + m, cmp2);
		for (int i = 0;i < m;i++) {
			int v = find(edges[i].from);
			int u = find(edges[i].to);
			if (u != v) {
				red += edges[i].cost;
				p[u] = v;
			}
		}
		if (blue >= k && red <= k) cout << 1 << endl;
		else cout << 0 << endl;

		cin >> n >> m >> k;
	}
	return 0;
}