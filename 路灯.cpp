//#include<iostream>
//using namespace std;
//
//int sum = 0, Less = 0;
//
//class pool {
//private:
//	int st, en, len, mk	;
//public:
//	pool() {
//		st = 0;
//		en = 0;
//		len = 0;
//		mk = 0;
//	}
//	void input() { cin >> st >> en >> len; }
//	void output() {
//		cout << st << " " << en << " " << len << " " << endl;
//	}
//	void InsertSort(pool s[], int m) {
//		for (int i = 0; i < m; ++i) {
//			for (int j = i; j > 0; --j) {
//				if (s[j].len < s[j - 1].len) {
//					pool temp;
//					temp = s[j];
//					s[j] = s[j - 1];
//					s[j - 1] = temp;
//				}
//			}
//		}
//	}
//	void sumlen() { sum += len; }
//	void zuixiao(pool s[],int m) {
//		s[0].mk = 1;
//		for (int i = 0; i < m; i++) {
//			if ((s[s[i].st].mk == 0 && s[s[i].en].mk == 1)|| (s[s[i].st].mk == 1 && s[s[i].en].mk == 0)) {
//				Less += s[i].len;
//				s[s[i].st].mk = 1;
//				s[s[i].en].mk = 1;
//			}
//		}
//	}
//};
//
//
//
//int main() {
//	int n, m, sumlen = 0;
//	freopen("input.txt", "r", stdin);
//	while (cin >> n >> m) {
//		if (n == 0 && m == 0) break;
//		pool s[200];
//		for (int i = 0; i < m; i++) {
//			s[i].input();
//			s[i].sumlen();
//		}
//		s[0].InsertSort(s, m);
//		for (int i = 0; i < m; i++) {
//			s[i].output();
//			s[i].zuixiao(s,i);
//		}
//		cout << sum << endl;
//		cout << Less << endl;
//		cout << sum - Less << endl;
//		sum = 0, Less = 0;
//	}
//	return 0;
//}
//
////#include<iostream>
////using namespace std;
////
////int sum = 0, Less = 0;
////
////class pool {
////private:
////	int st, en, len, mk;
////public:
////	pool() {
////		st = 0;
////		en = 0;
////		len = 0;
////		mk = 0;
////	}
////	void input() { cin >> st >> en >> len; }
////	void InsertSort(pool s[], int m) {
////		for (int i = 0; i < m; ++i) {
////			for (int j = i; j > 0; --j) {
////				if (s[j].len < s[j - 1].len) {
////					pool temp;
////					temp = s[j];
////					s[j] = s[j - 1];
////					s[j - 1] = temp;
////				}
////			}
////		}
////	}
////	void sumlen() { sum += len; }
////	void zuixiao(pool s[], int m) {
////		s[0].mk = 1;
////		for (int i = 0; i < m; i++) {
////			if ((s[s[i].st].mk == 0 && s[s[i].en].mk == 1) || (s[s[i].st].mk == 1 && s[s[i].en].mk == 0)) {
////				Less += s[i].len;
////				s[s[i].st].mk = 1;
////				s[s[i].en].mk = 1;
////			}
////		}
////	}
////};
////
////
////
////int main() {
////	int n=1, m, sumlen = 0;
////	while (cin >> n >> m) {
////		if (n == 0 && m == 0) break;
////		pool s[n];
////		for (int i = 0; i < m; i++) {
////			s[i].input();
////			s[i].sumlen();
////		}
////		s[0].InsertSort(s, m);
////		for (int i = 0; i < m; i++) {
////			s[i].zuixiao(s, i);
////		}
////		cout << sum - Less << endl;
////		sum = 0, Less = 0;
////	}
////	return 0;
////}

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

struct stream{
	int x, y, dis;
	stream() :x(0), y(0), dis(0) {}
}s[200000];

int f[200000];
int sum0, sum, rk, n, m;

bool cmp(stream a, stream b) {//sort,升序排列
	return a.dis < b.dis;
}

void init() {
	sum0 = 0;
	sum = 0;
	rk = n;
	for (int i = 0; i < 200000; i++)
		f[i] = i;
}

int find(int x)//建立连接,递归寻找根节点
{
	if (x != f[x])
		f[x] = find(f[x]);
	return f[x];
}

int join(stream a)//合并子树
{
	int fx = find(a.x);
	int fy = find(a.y);
	if (fx != fy)
	{
		f[fx] = fy;
		sum += a.dis;
		rk--;//取n-1条边
	}
	return rk;
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) && n)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].dis);
			sum0 += s[i].dis;
		}

		sort(s, s + m, cmp);//以cmp方法排序
		for (int i = 0; i < m; i++)
			if (join(s[i]) == 1)
			{
				printf("%d\n", sum0 - sum);
				break;
			}
	}
	return 0;
}