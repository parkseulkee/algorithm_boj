// 이친수

#include <iostream>
using namespace std;

long long int d[2][91];

int main()
{
	int n;
	cin >> n;

	d[1][1] = 1;

	for (int i = 2; i <= n; i++){
		d[0][i] += d[0][i - 1];
		d[0][i] += d[1][i - 1];
		d[1][i] += d[0][i - 1];
	}

	cout << d[0][n] + d[1][n] << endl;
	return 0;
}