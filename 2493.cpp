// 탑 : 스택

#include <iostream>
#include <stack>
using namespace std;

int d[500001];

struct element {
	int i;
	int v;
};

int main(void)
{
	stack<struct element> s;
	stack<struct element> k;
	int n;
	struct element value;
	struct element top;

	cin >> n;
	for (int i = 1;i <= n;i++) {
		value.i = i;
		cin >> value.v;
		s.push(value);
	}

	value = s.top();
	s.pop();
	k.push(value);

	while (!s.empty()) {
		top = s.top();
		s.pop();
		while (!k.empty()) {
			struct element tmp = k.top();
			if (top.v >= tmp.v) {
				d[tmp.i] = top.i;
				k.pop();
			}
			else {
				break;
			}
		}
		k.push(top);
	}

	for (int i = 1;i <= n;i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	return 0; 
}
