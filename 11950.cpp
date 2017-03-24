#include <iostream>
using namespace std;

int n, m;
int check[50][3];
int minResult;

void dfs(int result, int color, int index) {
	if (index > n - 2) {
		if (result < minResult) {
			minResult = result;
		}
		return;
	}
	// white
	if (color == 0) {
		if (index == n - 2) {
			dfs(result + m - check[index][1], 1, index + 1);
		}
		else {
			dfs(result + m - check[index][0], 0, index + 1);
			dfs(result + m - check[index][1], 1, index + 1);
		}
	}
	// blue
	else if (color == 1) {
		dfs(result + m - check[index][1], 1, index + 1);
		dfs(result + m - check[index][2], 2, index + 1);
	}
	// red
	else {
		dfs(result + m - check[index][2], 2, index + 1);
	}
}

int main()
{
	int result = 0;

	cin >> n >> m;
	char ch;
	minResult = n*m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> ch;
			if (ch == 'W') check[i][0]++;
			if (ch == 'B') check[i][1]++;
			if (ch == 'R') check[i][2]++;
		}
	}

	result += (m - check[0][0]);
	result += (m - check[n - 1][2]);
	
	dfs(0, 0, 1);

	cout << minResult + result << endl;
	return 0;
}