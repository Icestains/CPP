#include <iostream>
#include <string>
using namespace std;

void StrSort(string s[], int f, int n)//排序 
{
	while (f<--n)
	{
		int mx = 0;
		for (int i =  + 1; i <= n; i++)
		{
			if (s[mx]<s[i])
				mx = i;
		}
		swap(s[mx], s[n]);//交换 
	}
}

int main() {

	//freopen("input.txt", "r", stdin);//从文件获取 
	
	int n, max = 0;
	string s[105];
	int sum[105] = { 0 };

	while (cin >> n&&n != 0) {
		for (int i = 0; i < n; i++) {//输入 
			cin >> s[i];
		}
		StrSort(s, 0, n);//先排好序：） 
		for (int i = 0; i < n ; i++) {//找出现次数，用数组记录每个出现的次数 
			for (int j = i; j < n; j++) {//这里从每个i位置开始找，避免重复输出相同的 
				if (s[i] == s[j]) {
					sum[i]++;
					sum[i] > max ? max = sum[i] : max = max;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {//输出 
			if (sum[i] == max)//如果数组中记录的次数和最高次数相等，输出该下标对应的值 
				cout << s[i] << endl;
			sum[i] = 0;
		}
		max = 0;
	}
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//
//void StrSort(string s[], int lo, int hi)
//{
//	while (lo<--hi)
//	{
//		int mx = 0;
//		for (int i = lo + 1; i <= hi; i++)
//		{
//			if (s[mx]<s[i])
//				mx = i;//i就是每一趟最大值得下标
//		}
//		//cout<<s[mx]<<"<--swap_with-->"<<s[hi]<<endl;
//		swap(s[mx], s[hi]);
//	}
//}
//
//int  main()
//{
//	int N;
//	int i = 0;
//	//cin>>N;
//	freopen("input.txt", "r", stdin);
//	while (cin >> N&&N != 0)
//	{
//		string* s = new string[N];//用来存储各种颜色字符串的动态空间 
//		for (i = 0; i<N; i++) { cin >> s[i]; }//cout<<"s["<<i<<"]="<<s[i]<<endl;
//		StrSort(s, 0, N);
//		//for(i=0;i<N;i++){cout<<s[i]<<endl;}
//
//		int* count = new int[N];//去重 
//		for (i = 0; i<N; i++) { count[i] = 0; }
//		int l = 0, r = 0;
//		while (++r<N)
//		{
//			if (s[l] == s[r])count[l]++;
//			else { s[++l] = s[r]; }
//		}
//
//		int size = l + 1;//当前元素个数 
//		int mx = 0;
//		//cout<<"size="<<size<<endl;
//		for (i = 0; i<size; i++)
//		{
//			//cout<<"count[]="<<count[i]<<" ";
//			if (count[mx]<count[i])mx = i;
//			//cout<<"\nmx="<<mx<<endl;
//		}
//		for (i = 0; i<size; i++)
//		{
//			if (count[mx] == count[i])cout << s[i] << endl;
//		}
//		delete[]count;
//		delete[]s;
//	}
//	return 0;
//}
