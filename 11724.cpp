#include <iostream>
using namespace std;

int n, m;
int a[1001][1001];
bool check[1001] = { false, };

void dfs(int x) {
	check[x] = true;
	for (int i = 1;i <= n;i++) {
		if (a[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int s, e;
		cin >> s >> e;
		a[s][e] = a[e][s] = 1;
	}

	int component = 0;
	for (int i = 1;i <= n;i++) {
		if (check[i] == false) {
			dfs(i);
			component += 1;
		}
	}

	cout << component << endl;

	return 0;
}