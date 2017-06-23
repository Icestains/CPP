#include<iostream>
using namespace std;
int display(int c[205], int m) {
	int i = 0;
	for (; i < m; i++) {
		if (i == 0)
			cout << c[i];
		else
			cout << " " << c[i];
	}
	cout << endl;
	return 0;
}

int main(){
	int m, n;
	int a[205], b[105];
	while (cin >> m) {
		for (int i = 0; i < m; i++)
			cin >> a[i];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> b[i];
		display(a, m);
		display(b, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i] == a[j]) {
					display(a, m);
					break;
				}
				else if (j == m - 1) {
					a[m] = b[i];
					m++;
					display(a, m);
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

