#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int parent[10001];
int cost[10001];

int leaf[10001];

int main()
{
	int n, leafcnt;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		leaf[i] = i;
	}

	leafcnt = n;
	for (int i = 0;i < n-1;i++) {
		int p, c, v;
		scanf("%d %d %d", &p, &c, &v);
		parent[c] = p;
		cost[c] = v;
		if (leaf[p] != 10001) {
			leaf[p] = 10001;
			leafcnt--;
		}
	}
	sort(leaf, leaf + n + 1);
	int max = 0;
	for (int i = 1;i <= leafcnt+1;i++) {
		for (int j = i + 1;j <= leafcnt+1;j++) {
			int x = leaf[i], y = leaf[j];
			int sum = 0;
			while (x != y) {
				if (x > y) {
					sum += cost[x];
					x = parent[x];
				}
				else {
					sum += cost[y];
					y = parent[y];
				}
			}
			if (sum > max) max = sum;
		}
	}

	printf("%d\n", max);
	return 0;
}