#include<iostream>
using namespace std;

template<class T>//三元组
struct Trituple
{
	int row;
	int col;
	T val;
};

template<class T>//稀疏矩阵声明
class SparseMatrix
{
public:
	SparseMatrix(int maxt = 100);
	~SparseMatrix();
	//bool TransposeTo(SparseMatrix &);
	bool TransposeTo_Faster(SparseMatrix&);
	void Input(int row1, int col1);
	void Output();
private:
	Trituple<T>* data;
	int rows, cols, terms;
	int maxterms;
};

template<class T>//构造函数
SparseMatrix<T>::SparseMatrix(int maxt)
{
	maxterms = maxt;
	data = new Trituple<T>[maxterms];
	terms = rows = cols = 0;
}

template<class T>//析构函数
SparseMatrix<T>::~SparseMatrix()
{
	if (data != NULL)
	{
		delete[] data;
	}
}

//template<class T>//普通转置
//bool SparseMatrix<T>::TransposeTo(SparseMatrix &B)
//{
//	B.rows = cols;
//	B.cols = rows;
//	B.terms = terms;
//	if (terms>0)
//	{
//		int p = 0;
//		for (int j = 1; j <= cols; j++)
//		{
//			for (int k = 0; k<terms; k++)
//			{
//				if (data[k].col == j)
//				{
//					B.data[p].row = j;
//					B.data[p].col = data[k].row;
//					B.data[p].val = data[k].val;
//					p++;
//				}
//			}
//		}
//	}
//	return true;
//}

template<class T>//快速转置
bool SparseMatrix<T>::TransposeTo_Faster(SparseMatrix& B)
{
	
	B.rows = cols;
	B.cols = rows;
	B.terms = terms;
	if (terms>0)
	{
		int *num, *cpot;
		num = new int[cols];
		cpot = new int[cols];
		for (int j = 0; j<cols; j++)
		{
			num[j] = 0;
		}
		for (int k = 0; k<terms; k++)
		{
			num[data[k].col - 1]++;
		}
		//求出B中每一行的起始下标cpot[]
		cpot[0] = 0;
		for (int j = 1; j<cols; j++)
		{
			cpot[j] = cpot[j - 1] + num[j - 1];
		}
		//执行转置操作
		for (int p, k = 0; k<terms; k++)
		{
			p = cpot[data[k].col - 1]++;
			B.data[p].row = data[k].col;
			B.data[p].col = data[k].row;
			B.data[p].val = data[k].val;
		}
		delete[] num;
		delete[] cpot;
	}
	return true;
}

template<class T>
void SparseMatrix<T>::Input(int row1,int col1)
{
	
	int number;
	rows = row1;
	cols = col1;
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			cin >> number;
			if (number != 0)
			{
				data[terms].row = i + 1;
				data[terms].col = j + 1;
				data[terms].val = number;
				terms++;
			}
		}
	}
}

template<class T>  
void SparseMatrix<T>::Output()
{
	T **tempArray = new T*[rows];
	for (int i1 = 0; i1<rows; i1++)
	{
		tempArray[i1] = new int[cols];
	}

	for (int j = 0; j<rows; j++)
	{
		for (int k = 0; k<cols; k++)
		{
			tempArray[j][k] = 0;
		}
	}

	for (int i = 0; i<terms; i++)
	{
		tempArray[data[i].row - 1][data[i].col - 1] = data[i].val;
	}

	for (int j = 0; j<rows; j++)
	{
		for (int k = 0; k<cols; k++)
		{
				cout << tempArray[j][k]<< " " ;
			
		}
		cout << endl;
	}

	for (int l = 0; l<rows; l++)
	{
		delete[] tempArray[l];
	}
	delete tempArray;
}

int main()
{
	freopen("input.txt", "r", stdin);
	SparseMatrix<int> sm(1000);
	//SparseMatrix<int> sm1(50);
	SparseMatrix<int> sm2(1000);
	int c, r;
	while (cin>>c>>r) {
		sm.Input(c, r);
		/*sm.TransposeTo(sm1);
		sm1.Output();*/
		sm.TransposeTo_Faster(sm2);
		sm2.Output();
	}
	return 0;
}

