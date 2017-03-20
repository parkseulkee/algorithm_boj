// 최단거리 알고리즘

// 선택된 간선과 연결되어있는 간선만 검사
// 체크가 안된 것 중에 가중치가 가장 작은것 검사

#include <iostream>
using namespace std;

int map[1001][1001];
int d[1001];
bool c[1001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			map[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		if (map[x][y] > z)
			map[x][y] = z;
	}

	int st, ed;
	cin >> st >> ed;

	for (int i = 1; i <= n; i++){
		d[i] = 1000000000;
		c[i] = false;
	}

	d[st] = 0;

	for (int k = 0; k < n - 1; k++){
		int min = 1000000000 + 1;
		int minp = -1;
		for (int i = 1; i <= n; i++){
			if (c[i] == false && min > d[i]){
				min = d[i];
				minp = i;
			}
		}
		c[minp] = true;
		for (int i = 1; i <= n; i++){
			if (d[i] > d[minp] + map[minp][i]){
				d[i] = d[minp] + map[minp][i];
			}
		}
	}

	cout << d[ed] << endl;

	return 0;
}