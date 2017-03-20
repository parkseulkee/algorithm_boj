#include <iostream>
#include <algorithm>
using namespace std;

int a[9];
int d[9][9];

int main()
{
	int s = 0;
	for (int i = 0; i < 9; i++){
		cin >> a[i];
		s += a[i];
	}

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (i != j){
				d[i][j] = a[i] + a[j];
			}
		}
	}

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (i != j && s - d[i][j] == 100){
				a[i] = a[j] = 0;
				break;
			}
		}
	}

	sort(a, a + 9);

	for (int i = 2; i < 9; i++){
		cout << a[i] << endl;
	}

	return 0;
}