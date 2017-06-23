#include<iostream> 
#include <string.h>

using namespace std;

int searchseq(int *st, int length, int key) {
	int i = 0;
	st[0] = key;
	for (i = length; st[i] != key; --i);
	return i-1;
}

//int searchBin(int *st, int length, int key) {
//	int low = 0;
//	int high = length;
//	int mid = -1;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if (st[mid] == key) {
//			return mid-1;
//		}
//		else if (st[mid]>key) high = mid - 1;
//		else low = mid + 1;
//	}
//	return -1;
//}
	int List[5000] = { 0 };
	int Find[5050] = { 0 };
int main() {
	int n = 0, k = 0;


	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++)
			cin >> List[i];
		for (int i = 0; i < k; i++)
			cin >> Find[i];

		int index = -1;
		for (int i = 0; i < k; i++) {
			index = searchseq(List, n, Find[i]);
			//index = searchBin(List, n, Find[i]);
			cout << index << " ";
		}
		cout << endl;
		
		memset(List, 0, sizeof(List));
		memset(Find, 0, sizeof(Find));


	}

	return 0;
}