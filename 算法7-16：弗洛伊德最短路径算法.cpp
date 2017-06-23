#include<iostream>
#include<fstream>
using namespace std;

#define max 60
#define INF 9999
int n = max;
//ifstream in ("input.txt");

void Shortpath_Floyd(int n) {
	int D[max][max] = { 0 };
	int P[max][max] = { 0 };
	// ‰»Î
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (i == j) D[i][j] = 0;
			else if (temp == 0) D[i][j] = INF;
			else D[i][j] = temp;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) cout << 0 << " ";
			else if (i != j && D[i][j] >= INF) cout << -1 << " ";
			else
				cout << D[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	Shortpath_Floyd(n);
	return 0;
}