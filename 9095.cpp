// 1,2,3으로 만들기

#include <iostream>
using namespace std;

int d[12];

int main()
{
	int T;
	cin >> T;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int case_num = 1; case_num <= T; case_num++){
		int n;
		cin >> n;
		
		for (int i = 4; i <= n; i++){
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << endl;
	}
	return 0;
}