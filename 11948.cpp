// 과목선택 

#include <iostream>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main()
{
	int result = 0;
	int a[6];
	for (int i = 0;i < 6;i++) {
		cin >> a[i];
		result += a[i];
	}

	int index = 0;
	for (int i = 1;i < 4;i++) {
		if (a[i] < a[index]) index = i;
	}
	result -= a[index];
	result -= min(a[4], a[5]);

	cout << result << endl;
	return 0;
}