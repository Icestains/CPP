#include<iostream>
using namespace std;

int main()
{
	int arr[60][60], dist[60], final[60], i, j, n = 0, s = 0, v, w;
	int inf = 99999999;
	cin >> n >> s;

	for (i = 0; i < n; i++) {//输入数据
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (i = 0; i < n; i++) //初始化
	{
		final[i] = 0; dist[i] = arr[s][i];
	}

	dist[s] = 0; final[s] =1;

	for (i = 0; i < n-1; i++) {//主循环

		int min = inf;
		v = s;
		for (w = 0; w < n; w++) 
			if (!final[w] && dist[w] < min) {
				min = dist[w];
				v = w;
			}

		final[v] = 1;

		for (w = 0; w < n; w++)//更新当前最断路经及距离
			if (arr[v][w]<inf&&(arr[v][w] +dist[v])< dist[w] && !final[w] )
				dist[w] = dist[v] + arr[v][w];
	}

	for (i = 0; i < n; i++) {//输出
		if (i != s)
			cout << dist[i] << " ";
		else continue;
	}
				
	cout << endl;
	return 0;
}
