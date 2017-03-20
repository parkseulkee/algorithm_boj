// 차집합

// 1. 정렬
// 2. 정렬->이분탐색
// 3. set or map
// 4. 차집합 구하는 함수(set_difference)

// O(NM) 은 X

// 정렬 후 이분 탐색해서 없으면 출력 -> O(NlogM)
// 정렬 후 i,j 움직이면서 출력(위 ~ 아래 도 움직임) -> O(N+M) merge sort
// set A에서 B에 있는 것 삭제



#include <iostream>
#include <algorithm>
using namespace std;

int a[1000000];
int b[1000000];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 0; i < m; i++){
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + m);

	int ans = 0;
	int i = 0, j = 0;

	while (i < n && j < m){
		if (a[i] == b[j]){
			a[i] = -1;
			ans++; i++; j++;
		}
		else if (a[i] > b[j]) j++;
		else i++;
	}

	sort(a, a + n);

	if (ans == n){
		cout << "0" << endl;
	}
	else{
		cout << n - ans << endl;
		for (int i = ans; i < n; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}