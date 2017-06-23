#include<iostream>
using namespace std;

void SelectSort(int s[],int n) {
	int i = 0, j = 0, index;
	for (int i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++) 
			if (s[j] < s[index])
				index = j;
		if (index != i) {
			s[i] = s[i] + s[index];
			s[index] = s[i] - s[index];
			s[i] = s[i] - s[index];
		}
	}
}

int main() {
	int n;
	int s[1005] = { 0 };
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		SelectSort(s,n);
		for (int i = 0; i < n; i++) {
			cout << s[i] << " ";
		}
		cout << endl;
	}
}