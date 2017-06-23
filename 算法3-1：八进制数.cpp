#include <iostream>  
using namespace std;

int main()
{
	int n;
	int p = 8, c, m = 0, s[100];
	while (cin >> n) {
		while (n != 0) {
			c = n%8;
			n /= 8;
			m++;
			s[m] = c;
		}
		for (int k = m; k >= 1; k--) {
			cout << s[k];
			s[k] = 0;
		}
		m = 0;
		cout << endl;
	}
	return 0;
}