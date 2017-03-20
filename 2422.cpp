// N^3문제 200^3 가능
// 다 해보면 됨

#include <iostream>
using namespace std;


int a[201][201];


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	int ans = 0;
	for (int k = 1; k <= n; k++){
		for (int i = k+1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				if (!a[k][i] && !a[i][j] && !a[j][k]){
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}