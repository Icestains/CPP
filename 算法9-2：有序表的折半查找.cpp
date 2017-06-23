#include<iostream>  
using namespace std;

int searchBin(int *st, int length, int key) {
	int low = 0;
	int high = length-1;
	int mid = -1;
	int result = mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (st[mid] == key) {
			result = mid;
			if (mid > 0) {
				if (st[mid - 1] == key) {
					for (int i = mid - 1; i >= 0; i--) {
						if (st[i] == key) {
							result = i;
						}
						else break;
					}
				}
			}
			if (mid < high) {
				if (st[mid + 1] == key) {
					for (int i = mid + 1; i <= high; i++) {
						if (st[i] == key) {
							result = i-1;
						}
						else break;
					}
				}
			}
			return result;
		}
		else if (st[mid]>key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	int n = 0, k = 0;
	int List[1005] = { 0 };
	int Find[1005] = { 0 };

	while (cin >> n >> k) {
		for (int i = 0; i < n; i++)
			cin >> List[i];
		for (int i = 0; i < k; i++)
			cin >> Find[i];

		int index = -1;
		for (int i = 0; i < k; i++) {
			index = searchBin(List, n, Find[i]);
			cout << index << " ";
		}
		cout << endl;
	}

	return 0;
}