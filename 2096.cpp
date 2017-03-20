// 내려가기 : dp
#include <iostream>
#include <algorithm>
using namespace std;

int a[100000][3];
int dmax[2][3];
int dmin[2][3];


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		dmax[0][i] = a[0][i];
		dmin[0][i] = a[0][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dmax[1][j] = max(dmax[0][j], dmax[0][j + 1]) + a[i][j];
				dmin[1][j] = min(dmin[0][j], dmin[0][j + 1]) + a[i][j];
			}
			else if (j == 1) {
				dmax[1][j] = max(max(dmax[0][j - 1], dmax[0][j]), dmax[0][j + 1]) + a[i][j];
				dmin[1][j] = min(min(dmin[0][j - 1], dmin[0][j]), dmin[0][j + 1]) + a[i][j];
			}
			else {
				dmax[1][j] = max(dmax[0][j - 1], dmax[0][j]) + a[i][j];
				dmin[1][j] = min(dmin[0][j - 1], dmin[0][j]) + a[i][j];
			}
		}
		for (int j = 0; j < 3; j++) {
			dmax[0][j] = dmax[1][j];
			dmin[0][j] = dmin[1][j];
		}

	}

	printf("%d %d\n", max(max(dmax[0][0], dmax[0][1]), dmax[0][2]), min(min(dmin[0][0], dmin[0][1]), dmin[0][2]));

	return 0;
}