// 플로이드 : 플로이드-와샬 알고리즘

#include <iostream>
using namespace std;

int d[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	while (m--){
		int x, y, z;
		cin >> x >> y >> z;
		if (d[x][y] == 0){
			d[x][y] = z;
		}
		else{
			if (d[x][y] > z){
				d[x][y] = z;
			}
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0){
					if (d[i][j] == 0){
						d[i][j] = d[i][k] + d[k][j];
					}
					else{
						if (d[i][j] > d[i][k] + d[k][j]){
							d[i][j] = d[i][k] + d[k][j];
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}