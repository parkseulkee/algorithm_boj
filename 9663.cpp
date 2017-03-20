// N-Queen : 백트랙킹

#include <iostream>
#include <cmath>
using namespace std;

int arr[16];
int cnt;
int n;

bool check(int x, int y) {
	for (int i = 1; i < x; i++) {
		if (arr[i] == y) return false;
		if ((x - i) == abs(y - arr[i])) return false;
	}
	return true;
}

void backtraking(int x){
	if (x == n + 1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check(x, i)) {
			arr[x] = i;
			backtraking(x + 1);
		}
	}
}

int main()
{
	cin >> n;

	backtraking(1);

	cout << cnt << endl;

	return 0;
}