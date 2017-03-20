// 쉬운계단수

#include <iostream>
using namespace std;

int d[10][101];

int main()
{
	int result = 0;
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++){
		d[i][1] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= 9; j++){
			if (j - 1 >= 0){
				d[j - 1][i] += d[j][i - 1];
				d[j - 1][i] %= 1000000000;
			}
			if (j + 1 < 10){
				d[j + 1][i] += d[j][i - 1];
				d[j + 1][i] %= 1000000000;
			}
		}
	}

	for (int i = 0; i <= 9; i++){
		result += d[i][n];
		result %= 1000000000;
	}

	cout << result << endl;
	return 0;
}