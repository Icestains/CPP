#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int H;
	while (cin >> H) {
		cout << fixed << setprecision(1) << (H - 100)*0.9*2 << endl;
	}
	
	return  0;
}