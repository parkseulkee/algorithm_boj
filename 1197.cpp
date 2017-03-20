// 최소 스패닝 트리 : 최소 스패닝 트리

#include <iostream>
#include <algorithm>
using namespace std;

struct edge { int from; int to; int cost; };

struct edge edges[100000];
int p[100001];

bool cmp(struct edge a, struct edge b) {
	return a.cost < b.cost;
}

int find(int v) {
	if (p[v] == v) return v;
	else return p[v] = find(p[v]);
}

int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 0;i < e;i++) cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	for (int i = 1;i <= v;i++) p[i] = i;

	sort(edges, edges + e, cmp);

	int ans = 0;
	for (int i = 0;i < e;i++) {
		int u = find(edges[i].from);
		int v = find(edges[i].to);
		if (u != v) {
			ans += edges[i].cost;
			p[u] = v;
		}
	}
	cout << ans;
	return 0;
}