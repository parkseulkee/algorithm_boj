// 구간 합 구하기 : 세그먼트 트리

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// tree 구성
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	else return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

// 구간 합
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

// 수 변경
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<long long> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];

	// tree
	int h = (int)ceil(log2(n));
	int size = (1 << (h + 1));
	vector<long long> tree(size);

	init(a, tree, 1, 0, n - 1);
	for (int i = 0;i < m+k;i++) {
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		// b번째 수를 c로 바꿈
		if (aa == 1) {
			long long diff = cc - a[bb - 1];
			a[bb - 1] = cc;
			update(tree, 1, 0, n - 1, bb-1, diff);
		}
		// b~c 합
		else if (aa == 2) {
			cout << sum(tree, 1, 0, n - 1, bb - 1, cc - 1) << endl;
		}
	}
	return 0;
}