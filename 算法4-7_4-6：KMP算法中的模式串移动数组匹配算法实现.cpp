#include <iostream>
#include <string>
using namespace std;

void getNext(string S,int next[]) {
	int i = 0, k = -1;
	int slen = S.length();

	next[0] = -1;
	while (i < slen) {
		if (k == -1 || S[i] == S[k]) {
			i++;
			k++;
			next[i] = k;
		}
		else
			k = next[k];
	}
}

int fastfind(string &S, string &T, int k) {
	int posS = k, posT = 0;
	int lS = S.length();
	int lT = T.length();
	int next[105];
	getNext(T, next);
	while (posS < lS&&posT < lT) {
		if (posT == -1 || S[posS] == T[posT]) {
			posS++;
			posT++;
		}
		else
			posT = next[posT];
		
	}
	if (posT < lT) return 0;
	else return posS - lT+1;

}

int main() {
	string S,T;
	//freopen("input.txt", "r", stdin);//从文件获取 
	while (cin >> S>>T) {
		cout << fastfind(S, T, 0) << endl;
	}
}