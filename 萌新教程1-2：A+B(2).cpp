#include <iostream>
using namespace std;
int main() {
	int  M, a, i = 0, sum = 0;
	while (cin >> M) {
		if (M == 0)
			return 0;
		for (; i < M;i++ ) {
			cin >> a;
			sum = sum + a;
		}
		cout << sum << endl;
		sum = 0,i=0 ;
	}
	return 0;
}