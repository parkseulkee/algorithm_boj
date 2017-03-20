// 포도주 시식 : dp
#include <iostream>
using namespace std;

// d[i] = 포도주 i개 시식했을 때 최대값
int d[10001];
int c[10001];

int max(int a, int b){
	return a > b ? a : b;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> c[i];

	d[1] = c[1];
	d[2] = (c[1] + c[2]);

	for (int i = 1; i <= n; i++){
		d[i] = max(d[i - 1], d[i - 2] + c[i]);
		d[i] = max(d[i], d[i - 3] + c[i - 1] + c[i]);
	}

	cout << d[n] << endl;
	return 0;
}