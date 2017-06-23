#include <iostream>
using namespace std;
int main() {
	char s[100] = { 0 }, ss[100] = { 0 };
	while (cin >> s) {
		for (int i = 0; s[i] != 0; i++) {
			if (s[i] >= 'v'&&s[i] <= +'z' || s[i] >= 'V'&&s[i] <= +'Z')
				ss[i] = s[i] - 21;
			else
				ss[i] = s[i] + 5;
		}
		cout << ss << endl;
		for (int i = 0; s[i] != 0; i++)
			s[i] = ss[i] = 0;
	}
	return 0;
}