#include <iostream>
using namespace std;
int main() {
	int a, b,m,n,c;
	while (cin >> a >> b) {
		m = a, n = b;
		while (b!=0){
			c = a%b;
			a = b;
			b = c;
		}//aΪ�������
		cout << m/a << " " << n/a << endl;
	}
	return 0;
}