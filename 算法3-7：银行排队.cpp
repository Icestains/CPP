#include<iostream>
#include<iomanip>
using namespace std;

void shijian(int m, int total) {
	int s[205][2], c[25][2], n = m, t = 0;

	for (int i = 0; i < total; i++) {
		cin >> s[i][0] >> s[i][1];	
	}
	for (int i = 0; i < m; i++)
		c[i][0] = s[i][0], c[i][1] = s[i][1];
	while (n < total) {
		int x = 0;
		for (int i = 0; i < m - 1; i++) 
			if ((c[i][0] + c[i][1]) > (c[i + 1][0] + c[i+1][1])) x = i + 1;

		if ((c[x][0] + c[x][1]) > s[n][0]) {
			t = t + c[x][0] + c[x][1] - s[n][0];
			c[x][0] += c[x][1];
			c[x][1] = s[n][1];
		}
		else {
			c[x][0] = s[n][0];
			c[x][1] = s[n][1];
		}
		n++;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (double)t / total << endl;

}

int main() {
	int m, total;
	//freopen("input.txt", "r", stdin);//从文件获取 
	while (cin >> m >> total) {
		shijian(m,total);
	}
	return 0;
}


//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main() {
//	int m, total;
//	freopen("input.txt", "r", stdin);//从文件获取 
//	while (cin >> m >> total) {
//		int a[200], b[200], c[200], d[200], n = m;
//
//		for (int i = 0; i < total; i++)
//			cin >> a[i] >> b[i];
//
//		for (int i = 0; i < m; i++)
//		{
//			c[i] = b[i]; d[i] = a[i];
//		}
//
//		int t = 0;
//		while (n < total) {
//			int x = 0;
//			for (int i = 0, y = d[i] + c[i]; i < m - 1; i++) {
//				if (y >(d[i + 1] + c[i + 1])) {
//					x = i + 1; y = d[i + 1] + c[i + 1];
//				}
//			}
//
//			if ((d[x] + c[x]) > a[n]) {
//				t = t + d[x] + c[x] - a[n];
//				d[x] += c[x];
//				c[x] = b[n];
//			}
//
//			else {
//				d[x] = a[n];
//				c[x] = b[n];
//			}
//			n++;
//		}
//		cout << setiosflags(ios::fixed) << setprecision(2) << (double)t / total << endl;
//	}
//}