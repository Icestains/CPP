#include<iostream>
using namespace std;
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}

int main()
{
	int len = 0;
	int array[100005] = { 0 }, k;
	cin >> len;
	for (k = 0; k < len; k++)
		cin >> array[k];
	quickSort(array, 0, len - 1);
	for (k = 0; k<len; k++)
		cout << array[k] << " ";
	cout << endl;
	return 0;
}

//#include<iostream>
//using namespace std;
//void quickSort(int a[], int, int);
//int main()
//{
//	int array[] = { 2,8,4,6,1,10,7,3,5,9 }, k;
//	int len = sizeof(array) / sizeof(int);
//	for (k = 0; k<len; k++)
//		cout << array[k] << " ";
//	cout << endl;
//	quickSort(array, 0, len - 1);
//	for (k = 0; k<len; k++)
//		cout << array[k] << " ";
//	cout << endl;
//	return 0;
//}
//void quickSort(int s[], int l, int r)
//{
//	if (l < r)
//	{
//		int i = l, j = r, x = s[l];
//		while (i < j)
//		{
//			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
//				j--;
//			if (i < j)
//				s[i++] = s[j];
//
//			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
//				i++;
//			if (i < j)
//				s[j--] = s[i];
//		}
//		s[i] = x;
//		quickSort(s, l, i - 1); // 递归调用
//		quickSort(s, i + 1, r);
//	}
//}