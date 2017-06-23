#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	string a;
	int k = 0;
	while (cin >> a)
	{
		stack<char> s;
		int n = a.length();
		//int n = strlen(a);
		for (int i = 0; i<n; i++)
		{
			switch (a[i])
			{
			case'(':s.push(a[i]),k++; break;
			case')':s.pop(),k--; break;
			case'G': cout << k << endl;break;
			}
		}
		
		k = 0;
	}
}

