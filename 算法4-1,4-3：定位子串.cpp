#include <iostream>
#include <string>
using namespace std;

void findstr(string &a, string &b) {
	int i = 0, j = 0;
	int la = a.length(), lb = b.length();
	while (i < la && j < lb) {
		//cout << a[i];
		if (a[i] == b[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	//cout << endl;
	if (j < lb)cout << 0 << endl;
	else cout << i - j + 1 << endl;
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		findstr(a, b);
	}
}
