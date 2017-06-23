#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;

bool isdigit(char ch) {
	if (ch >= '0'&&ch <= '9')return true;
	else return false;
}

int getPriority(char op) {
	int pr;
	if (op == '#')
		pr = 3;
	else if (op == '*' || op == '/')
		pr = 2;
	else if (op == '+' || op == '-')
		pr = 1;
	else if (op == '(')
		pr = 0;
	return pr;
}

void calculate(stack<int> &opdStack, char opt) {
	if (opt == '+')
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd + rOpd;
		opdStack.push(result);
	}
	else if (opt == '-')
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd - rOpd;
		opdStack.push(result);
	}
	else if (opt == '*')
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd * rOpd;
		opdStack.push(result);
	}
	else if (opt == '/')
	{
		int rOpd = opdStack.top();
		opdStack.pop();
		int lOpd = opdStack.top();
		opdStack.pop();
		int result = lOpd / rOpd;
		opdStack.push(result);
	}
}

void cclt(string T) {
	stack<int> dt;
	stack<char> op;
	int size = T.length();
	int i = 0;
	int Isnumber = 0;

	for (i = 0; i < size&&T[i]!='#'; i++) {
		char t = T[i];
		if (t == '+' || t == '-' || t == '*' || t == '/') {
			if (op.size() == 0) {
				op.push(t);
				Isnumber = 0;
			}
			else {
				int tpr = getPriority(t);
				char topop = op.top();
				int toppr = getPriority(topop);
				if (tpr > toppr) {
					op.push(t);
					Isnumber = 0;
				}
				else {
					while (tpr <= toppr) {
						op.pop();
						calculate(dt, topop);
						if (op.size() > 0) {
							topop = op.top();
							toppr = getPriority(topop);
						}
						else break;
					}
					op.push(t);
					Isnumber = 0;
				}
			}
		}
		else if (t == '(')
		{
			op.push(t);
		}
		else if (t == ')')
		{
			while (op.top() != '(')
			{
				char topop = op.top();
				calculate(dt, topop);
				op.pop();
			}
			op.pop();
		}
		else  //如果是操作数，直接入操作数栈
		{
			int s = t - '0';
			if (Isnumber==1&&!dt.empty()&&dt.top() >= 0 && dt.top() <= 9) {
				s = dt.top() * 10 + s;
				dt.pop();
				dt.push(s);
				Isnumber = 1;
			}
			else {
				dt.push(s);
				Isnumber = 1;

			}
		}
	}
	while (op.size() != 0)
	{
		char topop = op.top();
		if (topop != '#') {
			calculate(dt, topop);
			op.pop();
		}
	}
	cout << dt.top() << endl;
}

int main() {
	string T;
	while (cin >> T)
		cclt(T);
	return 0;
}