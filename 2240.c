// 자두나무 : dp

#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int d[2][1005][35];
int a[1005];

int main(void) {

	int t,w;
	int maxResult = 0;

	scanf("%d %d", &t, &w);

	for (int i = 1; i <= t; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= t; i++) {
		for (int k = 0; k <= w; k++)
		{
			if (a[i] == 1)
			{
				d[0][i][k] = max(d[1][i - 1][k - 1] + 1, d[0][i - 1][k] + 1);

				d[1][i][k] = max(d[0][i - 1][k - 1], d[1][i - 1][k]);

			}
			else
			{
				d[0][i][k] = max(d[1][i - 1][k - 1], d[0][i - 1][k]);

				d[1][i][k] = max(d[0][i - 1][k - 1] + 1, d[1][i - 1][k] + 1);
			}
		}


	}

	for (int k = 0; k <= w; k++) {
		maxResult = max(maxResult, d[0][t][k]);
		maxResult = max(maxResult, d[1][t][k]);

	}

	printf("%d\n", maxResult);

	return 0;
}

