// 번호표 교환 : 단순 반복
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n, m;
	int a[1000];
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> a[i];

	for (int i = 2;i <= m;i++) {
		for (int j = 0;j < n - 1;j++) {
			if (a[j] % i > a[j + 1] % i) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 0;i < n;i++) {
		cout << a[i] << endl;
	}
	return 0;
}