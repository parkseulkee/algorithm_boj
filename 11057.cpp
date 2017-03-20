// 오르막수

#include <iostream>
using namespace std;

int d[10][1001];


int main()
{
	int n;
	int result = 0;
	cin >> n;

	for (int i = 0; i <= 9; i++){
		d[i][1] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= 9; j++){
			for (int k = j; k <= 9; k++){
				d[k][i] += d[j][i - 1];
				d[k][i] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++){
		result += d[i][n];
		result %= 10007;
	}
	cout << result << endl;

	return 0;
}