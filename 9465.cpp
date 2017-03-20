// 스티커 : dp

#include <iostream>
#include <algorithm>
using namespace std;

int d[2][100001];


int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++){
		int n;
		cin >> n;
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> d[i][j];

		if (n == 1){
			cout << max(d[0][1], d[1][1]) << endl;
			continue;
		}
		d[0][2] += d[1][1];
		d[1][2] += d[0][1];

		for (int j = 3; j <= n; j++){
			int temp = max(d[0][j - 2], d[1][j - 2]);
			d[0][j] += max(temp, d[1][j - 1]);
			d[1][j] += max(temp, d[0][j - 1]);
		}

		cout << max(d[0][n], d[1][n]) << endl;
	}
	return 0;
}