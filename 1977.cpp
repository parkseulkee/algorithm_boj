// 완전 제곱수

#include <iostream>
using namespace std;

int main(){ 
	int n, m;
	cin >> n >> m;

	int i = 0;
	int t = -1;
	int s = 0;

	while (i*i <= m){
		if (i*i >= n){
			s += i*i;
			if (t == -1)	t = i*i;
		}
		i++;
	}

	
	if (t == -1) cout << t << endl;
	else{
		cout << s << endl << t << endl;
	}

	return 0;
}