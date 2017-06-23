#include<iostream>
using namespace std;

void BinaryInsertSort(int *a, int n)
{
	int i, j, low, mid, high;
	int temp;
	for (i = 1; i<n; i++)
	{
		if (a[i - 1]>a[i])
		{
			temp = a[i];
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (temp<a[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
				a[j + 1] = a[j];
			a[j + 1] = temp;
		}
	}
}

void InsertSort(int *a, int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
	temp = a[i];
	for (j = i - 1; j >= 0 && a[j] > temp; j--)
		a[j + 1] = a[j];
	a[j + 1] = temp;
	}
}

int main()
{
	int n = 0;
	int a[1005] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//BinaryInsertSort(a, n);
	InsertSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}