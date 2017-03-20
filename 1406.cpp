// 문자열 직접 조작 X
// 1. 링크드 리스트 #include <list>
// 2. 스택

// 스택사용해서 풀기
// stack | stack

#include <iostream>
#include <stack>
using namespace std;


stack<char> l;
stack<char> r;

int main()
{
	char ch;

	while ((ch = cin.get()) != '\n'){
		l.push(ch);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch;
		switch (ch){
		case 'L':
			if (!l.empty()){
				ch = l.top();
				l.pop();
				r.push(ch);
			} 
			break;
		case 'D': 
			if (!r.empty()){
				ch = r.top();
				r.pop();
				l.push(ch);
			}
			break;
		case 'B': 
			if(!l.empty())
				l.pop(); 
			break;
		case 'P': 
			cin >> ch;
			l.push(ch);
			break;
		}
	}

	while (!l.empty()){
		ch = l.top();
		l.pop();
		r.push(ch);
	}

	while (!r.empty()){
		ch = r.top();
		r.pop();
		cout << ch;
	}

	cout << endl;
	return 0;
}