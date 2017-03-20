// 키로거 : 스택

#include <iostream>
#include <stack>
using namespace std;

char str[1000000];
stack <char> l;
stack <char> r;

void key(char *buf){
	char ch;
	for (int i = 0; buf[i] != '\0'; i++){
		if (buf[i] == '<' && !l.empty()){
			ch = l.top();
			l.pop();
			r.push(ch);
		}
		else if (buf[i] == '>' && !r.empty()){
			ch = r.top();
			r.pop();
			l.push(ch);
		}
		else if (buf[i] == '-' && !l.empty()){
			l.pop();
		}
		else if(buf[i] !='<' && buf[i] != '>' && buf[i] != '-'){
			l.push(buf[i]);
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
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> str;
		key(str);
	}
	return 0;
}