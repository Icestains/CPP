#include<iostream>
#include<stdio.h>
using namespace std;

int i = 1;

void move(char fr, int n, char to) {
	printf("%2d. Move disk %d from %c to %c\n", i++, n, fr, to);
}

void hanoi(int n, char x, char y, char z) {
	if (n == 1)
		move(x, 1, z);
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}

}

int main() {
	int num = 0;
	while (cin >> num) {
		char a = 'X', b = 'Y', c = 'Z';
		hanoi(num, a, b, c);
		cout << endl;
		i = 1;
	}
	return 0;
}