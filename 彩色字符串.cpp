#include <iostream>
#include <cstdio>
#include <stack>
#include <string.h>
using namespace std;

void sum(stack<int> &ss,int &n) {
	
	while (ss.top() != '('&&ss.top() != '<'&&ss.top() != '[') {
		ss.pop();
		n++;
	}
	ss.pop();
}

void threeColor(char s[]) {
	int rd = 0, gn = 0, bl = 0,i=0,lenth=strlen(s);
	stack<int> ss;
	for (i = 0; i < lenth; i++) {
		switch (s[i]) {
			case ')':sum(ss, rd); break;
			case '>':sum(ss, gn); break;
			case ']':sum(ss, bl); break;
			default:ss.push(s[i]); break;
		}
	}
	cout << rd << " " << gn << " " << bl << endl;
	//return 0;
}

int main() {
	char s[1000] = { 0 };
	int n=0;
	freopen("input.txt", "r", stdin);
	
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			threeColor(s);
		}
		for (int i = 0; i < strlen(s); i++) {
			s[i] = 0;
		}
		
	}
	return 0;
}
