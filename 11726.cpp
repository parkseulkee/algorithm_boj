// 2*n 타일링 : dp

#include <iostream>
using namespace std;

int d[1001];

int main()
{
	int n;
	cin >> n;

	d[0] = d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++){
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}

	cout << d[n]<< endl;

	return 0;
}