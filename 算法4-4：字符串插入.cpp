#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void Inserti(string&a, string&b,int i) {
	int j = 0;
	for ( j = 0; j < i; j++) {
		cout << a[j];
	}
	cout << b ;
	for ( ; j < a.length(); j++)
		cout << a[j];
	cout << endl;
}

int main() {
	int i=0, la=0, lb=0;
	string a, b;
	while (cin >> a >> b >> i) {
		Inserti(a, b, i-1);
	}
	return 0;
}