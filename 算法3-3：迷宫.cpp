#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

#define N 10

struct MazeCell {
	int i, j; //行列
	char sign;  //符号
	int direction; //1 2 3 4分别表示东南西北
};

class Maze {
private:
	MazeCell Map[N][N];
	MazeCell start;
	MazeCell end;
public:
	void inputMap() {
		for (int i = 0; i < N; i++) {
			char str[N + 1];
			gets_s(str);
			for (int j = 0; j < N; j++) {
				Map[i][j].sign = str[j];
				Map[i][j].direction = 0;
				Map[i][j].i = i;
				Map[i][j].j = j;

				if (Map[i][j].sign == 'S') {
					start = Map[i][j];
				}
				if (Map[i][j].sign == 'E') {
					end = Map[i][j];
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << Map[i][j].sign;
			}
			cout << endl;
		}
	}

	bool IsPath(int i, int j) {
		return Map[i][j].sign != '!' &&  Map[i][j].sign != '#' && Map[i][j].direction == 0;
	}

	void findPath() {
		stack<MazeCell> path;
		path.push(start);
		MazeCell m = start;
		while (!path.empty() && path.top().sign != end.sign) {
			m = path.top();
			int i = m.i, j = m.j;
			m = Map[i][j];  //取栈顶
			if (m.direction == 0 || m.direction == 1) {
				++j;
				if (IsPath(i, j)) {
					path.push(Map[i][j]);  //下一步可走，压入栈中
					Map[m.i][m.j].sign = '*'; //标记当前可走
					Map[m.i][m.j].direction = 1;
				}
				else
				{
					Map[m.i][m.j].direction = 2;
				} //走不通就换方向
			}
			else if (m.direction == 2) {
				i++;
				if (IsPath(i, j)) {
					path.push(Map[i][j]);  
					Map[m.i][m.j].sign = '*';
					Map[m.i][m.j].direction = 2;
				}
				else
				{
					Map[m.i][m.j].direction = 3;
				}
			}
			else if (m.direction == 3) {
				j--;
				if (IsPath(i, j)) {
					path.push(Map[i][j]);  
					Map[m.i][m.j].sign = '*'; 
					Map[m.i][m.j].direction = 3;
				}
				else Map[m.i][m.j].direction = 4; 
			}
			else if (m.direction == 4) {
				i--;
				if (IsPath(i, j)) {
					path.push(Map[i][j]);  
					Map[m.i][m.j].sign = '*'; 
					Map[m.i][m.j].direction = 4;
				}
				else Map[m.i][m.j].direction = 5; 
			}
			else if (m.direction == 5) {
				Map[m.i][m.j].sign = '!';
				path.pop();//出栈
				continue;
			}
			else { Map[m.i][m.j].sign = '!'; break; }
		}
		if (path.empty()) return;
		Map[end.i][end.j].sign = '*';
	}
};
int main() {

	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	Maze m;
	m.inputMap();
	m.findPath();
	m.print();

	return 0;
}