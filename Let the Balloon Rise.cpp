#include <iostream>
#include <string>
using namespace std;

void StrSort(string s[], int f, int n)//���� 
{
	while (f<--n)
	{
		int mx = 0;
		for (int i =  + 1; i <= n; i++)
		{
			if (s[mx]<s[i])
				mx = i;
		}
		swap(s[mx], s[n]);//���� 
	}
}

int main() {

	//freopen("input.txt", "r", stdin);//���ļ���ȡ 
	
	int n, max = 0;
	string s[105];
	int sum[105] = { 0 };

	while (cin >> n&&n != 0) {
		for (int i = 0; i < n; i++) {//���� 
			cin >> s[i];
		}
		StrSort(s, 0, n);//���ź��򣺣� 
		for (int i = 0; i < n ; i++) {//�ҳ��ִ������������¼ÿ�����ֵĴ��� 
			for (int j = i; j < n; j++) {//�����ÿ��iλ�ÿ�ʼ�ң������ظ������ͬ�� 
				if (s[i] == s[j]) {
					sum[i]++;
					sum[i] > max ? max = sum[i] : max = max;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {//��� 
			if (sum[i] == max)//��������м�¼�Ĵ�������ߴ�����ȣ�������±��Ӧ��ֵ 
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
//				mx = i;//i����ÿһ�����ֵ���±�
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
//		string* s = new string[N];//�����洢������ɫ�ַ����Ķ�̬�ռ� 
//		for (i = 0; i<N; i++) { cin >> s[i]; }//cout<<"s["<<i<<"]="<<s[i]<<endl;
//		StrSort(s, 0, N);
//		//for(i=0;i<N;i++){cout<<s[i]<<endl;}
//
//		int* count = new int[N];//ȥ�� 
//		for (i = 0; i<N; i++) { count[i] = 0; }
//		int l = 0, r = 0;
//		while (++r<N)
//		{
//			if (s[l] == s[r])count[l]++;
//			else { s[++l] = s[r]; }
//		}
//
//		int size = l + 1;//��ǰԪ�ظ��� 
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
