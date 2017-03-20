// 동전0 : 그리디 알고리즘

#include <iostream>
using namespace std;

int n, k;
int a[10];
int result;

int main()
{
	cin >> n >> k;
	for (int i = 0;i < n;i++) cin >> a[i];

	for (int i = n - 1;i >= 0;--i) {
		result += (k / a[i]);
		k -= ((k / a[i])*a[i]);
		if(k == 0) break;
	}
	cout << result << endl;
	return 0;
}