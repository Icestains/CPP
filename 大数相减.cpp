#include <iostream>
#include <string>
using namespace std;
void xiangjian(string &a, string &b) {
	int p[105] = { 0 };
	int q[105] = { 0 };
	int i = 0, j = 0, n = 0, k = 0;
	for (i = a.length() - 1; i >= 0; i--) {
		p[n] = a[i] - '0';
		n++;
	}
	for (i = b.length() - 1; i >= 0; i--) {
		q[k] = b[i] - '0';
		k++;
	}
	i = 0;
	while (i < 104)
	{
		p[i] -= q[i];
		if (p[i] < 0)
		{
			p[i + 1]--;
			p[i] += 10;
		}
		i++;
	}
	for (i = 104; i >= 0; i--) {
		if (p[i] != 0) {
			j = i;
			break;
		}
	}
		
	for (i = j; i >= 0; i--) {
		cout << p[i];
	}
		
	cout << endl;

}
int main() {
	string a;
	string b;
	while (cin >> a >> b) {
		xiangjian(a, b);
	}
	return 0;
}