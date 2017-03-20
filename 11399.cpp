// ATM : 그리디 알고리즘

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int p[1000];
	cin >> n;
	for (int i = 0;i < n;i++) cin >> p[i];
	sort(p, p + n);

	int result = 0;
	for (int i = 0;i < n-1;i++) {
		p[i + 1] += p[i];
		result += p[i];
	}
	
	cout << result+p[n-1] << endl;
	return 0;
}