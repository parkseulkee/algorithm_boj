// 무한 이진 트리

// (a,b) 
// (a+b,b) : a>b 왼 parent (a+b-b,b)
// (a,b+a) : a<b 오 parent (a,a+b-a)
// 느림


// (1,2) (3,2) (5,2) 5->1 5/2 5%2 한번에 올라가기

#include <iostream>
using namespace std;

int l, r;

int main()
{
	int a, b;
	cin >> a >> b;

	while (a != 1 || b != 1){
		if (a > b){
			if (b == 1){
				l += ((a / b) - 1);
				a = 1;
			}
			else{
				l += (a / b);
				a = (a%b);
			}
		}
		else{
			if (a == 1){
				r += ((b / a) - 1);
				b = 1;
			}
			else{
				r += (b / a);
				b = (b%a);
			}

		}
	}

	cout << l << ' ' << r << endl;
	return 0;
}