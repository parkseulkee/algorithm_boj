// 순열 

#include <cstdio>
#include <vector>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool next_permutation(vector<int> &a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		--i;
	}
	// input 5 : 5 4 3 2 1 case
	if (i <= 0) return false;

	int j = n - 1;
	while (a[j] <= a[i - 1]) --j;
	swap(a[i-1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> a;
	for (int i = 0;i < n;i++) a.push_back(i + 1);

	do {
		for (int i = 0;i < n;i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	} while (next_permutation(a,n));

	return 0;
}