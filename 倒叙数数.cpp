#include <iostream>
using namespace std;
int number(int s) {
	int sum = 0, ss = 0;
	while (s) {
		ss = ss * 10 + s % 10;
		s /= 10;
		sum++;
	}
	cout << sum << " " << ss << endl;
	return 1;
}
int main() {
	int n, s[10];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			number(s[i]);
			s[i] = 0;
		}
	}
	return 0;
}