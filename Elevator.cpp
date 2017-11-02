#include<iostream>
using namespace std;
int main() {
	int n = 0, i = 0; 
	int m[105] = { 0 };
	while (cin>> n&&n!=0) {
		int shang = 0, xia = 0;
		for (i = 1; i <= n; i++) cin >> m[i];//���� 
		for (i = 0; i < n; i++) {
			if ((m[i + 1] - m[i]) < 0)//��¥ 
				xia = xia + m[i + 1] - m[i];
			else//��¥ 
				shang = shang + m[i + 1] - m[i];
		}
		cout << n * 5 + shang * 6 - xia * 4 << endl;
	}
	return 0;
}


