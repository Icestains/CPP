#include <iostream>
using namespace std;
int main() {
	int n = 0;
	int h = 0, m = 0, s = 0, ss[15] = { 0 };
	char str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h >> str >> m >> str >> s;
		ss[i] = s + m * 60 + h * 3600;
	}
	for (int i = 0; i < n; i++) {
		cout << ss[i] << endl;
	}
	return 0;
}