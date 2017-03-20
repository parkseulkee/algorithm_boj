#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
	int from, to, cost;
};

Edge edges[100000];
int p[100001];

int find(int x){
	if (p[x] == x)
		return x;
	else
		return p[x] = find(p[x]);
}

bool cmp(Edge e1, Edge e2){
	return e1.cost < e2.cost;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	}

	for (int i = 1; i <= n; i++){
		p[i] = i;
	}

	sort(edges, edges + m, cmp);

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int x = find(edges[i].from);
		int y = find(edges[i].to);
		if (x != y){
			p[x] = y;
			ans += edges[i].cost;
		}
	}
	cout << ans;
	return 0;
}