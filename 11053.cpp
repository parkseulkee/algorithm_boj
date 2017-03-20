// 가장 긴 증가하는 부분 수열 : dp

#include <iostream>
#include <algorithm>
using namespace std;

int a[1000];
int d[1000];

bool cmp(int a, int b){
	return a > b ? true : false;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++){
		d[i] = 1;
		for (int j = 0; j < i; j++){
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	sort(d, d + n, cmp);
	cout << d[0] << endl;
	return 0;
}