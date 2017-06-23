#include <iostream> 
using namespace std;

int main() {
	int n, m;
	//freopen("input.txt", "r", stdin);
	cin >> m;
	while (m--) {
		cin >> n;
		int ss[100] = { 0 }, tree[100] = { -1 },s[100][2];;
		for (int i = 1; i <= n; i++) 
			for(int j=0;j<2;j++)
			cin >> s[i][j];
		
		for (int k = 1; k <= n; k++) {
			for (int j = 0; j < 2; j++)
				if (s[k][j] != -1)
					ss[s[k][j]] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (!ss[i]) {
				tree[1] = i;
				break;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (tree[i] != -1) {
				int z = tree[i];
				tree[i * 2] = s[z][0];
				tree[i * 2 + 1] = s[z][1];
			}
		}
		int zz=0;
		for (int i = 1; i <= n; i++) {
			if (tree[i] == -1) zz++;
			tree[i] = -1;
		}
		if(zz==0)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;

			
	}return 0;
}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	freopen("input.txt", "r", stdin);
//	cin >> n;
//	while (n--)
//	{
//		int in[100][2] = { 0 };
//		int k;
//		cin >> k;
//		for (int i = 1; i <= k; i++)
//			for (int j = 0; j < 2; j++)
//				cin >> in[i][j];
//
//		int a[100] = { 0 };
//
//		for (int i = 1; i <= k; i++)
//			for (int j = 0; j < 2; j++)
//			{
//				if (in[i][j] != -1)
//					a[in[i][j]] = 1;
//			}
//
//		int tree[100] = { 0 };
//
//		for (int i = 0; i < 62; i++) tree[i] = -1;
//
//		int root;
//		for (int i = 1; i <= k; i++)
//			if (!a[i])
//			{
//				root = i;
//				tree[1] = i;
//			}
//		//	cout << root;
//		for (int i = 1; i <= k; i++)
//		{
//			if (tree[i] != -1)
//			{
//				tree[2 * i] = in[tree[i]][0];
//				tree[2 * i + 1] = in[tree[i]][1];
//			}
//		}
//
//		//	for (int i = 1; i <= 30; i++) cout << tree[i];
//
//		int num = 0;
//		for (int i = 1; i <= k; i++)
//		{
//			if (tree[i] == -1)
//				num++;
//		}
//		if (num == 0) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	//	system("pause");
//	return 0;
//}