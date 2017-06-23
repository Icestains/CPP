//#include<iostream>
//using namespace std;
//int main() {
//	int n = 0;
//	int s[1005] = { 0 };
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> s[i];
//	shellsort(s,)
//}

#include <iostream>
using namespace std;

void shell_sort(int arr[], int len)
{
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}

int main()
{
	int n;
	int a[1005] = { 0 };
	cin >> n;
	for (int i = 0; i<n; i++)
		cin>>a[i];
	shell_sort(a, n);
	for (int i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}

