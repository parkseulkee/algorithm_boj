// 붕어빵 판매하기

#include <iostream>
using namespace std;

int d[1001];


int max(int a, int b){
	return a > b ? a : b;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		int c;
		cin >> c;
		d[i] = c;
	}


	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			d[i] = max(d[i], d[i - j] + d[j]);
		}
	}

	cout << d[n] << endl;
	return 0;
}