#include<iostream>
using namespace std;

struct BiNode {
	int data;
	BiNode *lc, *rc;
};

bool insertbst(BiNode *&T, int key) {
	if (T == NULL) {
		T = new BiNode();
		T->lc = T->rc = NULL;
		T->data = key;
		return true;
	}
	if (key < T->data)
		insertbst(T->lc, key);
	else if(key>T->data)
		insertbst(T->rc, key);
	else return false;
}

BiNode* creatBitree(BiNode *&tree, int d[], int n) {
	for (int i = 0; i < n; i++)
		insertbst(tree, d[i]);
	return tree;
}

int SearchBST(BiNode *&T,int key) {
	if (T==NULL) {
		return 0;
	}
	else if (key == T->data) return 1;
	else if (key < T->data)
		SearchBST(T->lc, key);
	else SearchBST(T->rc, key);
}

int main() {
	int n = 0, k = 0;
	BiNode *T = NULL;
	while (cin >> n >> k) {
		int arr[505] = { 0 }, Find[505]{ 0 };
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		creatBitree(T, arr, n);
		for (int i = 0; i < k; i++) {
			cin >> Find[i];
			cout << SearchBST(T, Find[i]) << " ";
		}
		cout << endl;
	}
	return 0;
}

//#include<malloc.h>
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//typedef struct BiTNode {
//	int data;
//	int flag;
//	struct BiTNode *lchild, *rchild;
//}BTNode, BTree;
////二叉排序树的查找非递归算法
////在二叉排序树T中查找关键字为key的元素，若找到返回true,
////否则返回false.
//bool SearchBST(BTree *T, int key) {
//	BTree *p = T;
//	while (p) {
//		if (p->data == key)
//			return true;
//		p = (key<p->data) ? p->lchild : p->rchild;
//	}
//	return false;
//}
////二叉排序树的查找递归算法
////在二叉排序树T中查找关键字为key的元素，若找到返回true,
////否则返回false.
//bool SearchBST2(BTree *T, int key) {
//	BTree *p = T;
//	if (!p)
//		return false;
//	else
//		if (p->data == key)
//			return true;
//		else
//			if (key>p->data)
//				return SearchBST2(p->rchild, key);
//			else
//				return SearchBST2(p->lchild, key);
//}
////建立二叉排序树
////当二叉排序树T中不存在关键字为key的元素时，插入key,并返回树的根，
////否则不插入,并返回树的根。   
//BTree* InsertBST(BTree *T, int key) {
//	BTree *f = T, *p = T;
//	while (p) {
//		if (p->data == key) return T;
//		f = p;//用f记下查找路径上的最后一个访问的节点
//		p = (key<p->data) ? p->lchild : p->rchild;
//	}
//	p = (BTNode*)malloc(sizeof(BTNode));
//	p->data = key;
//	p->lchild = p->rchild = NULL;
//	if (T == NULL)
//		T = p;
//	else
//		if (key<f->data)
//			f->lchild = p;
//		else
//			f->rchild = p;
//	return T;
//}
////递归中序遍历
//void InOrderDisplay(BTree *T) {
//	if (T) {
//		InOrderDisplay(T->lchild);
//		cout << T->data;
//		InOrderDisplay(T->rchild);
//	}
//}
////test:
//int main() {
//	int i;
//	int data;
//	BTree *tree = NULL;
//	for (i = 0; i<4; i++) {
//		cout << "input data" << endl;
//		cin >> data;
//		tree = InsertBST(tree, data);
//	}
//	InOrderDisplay(tree);
//	bool find = SearchBST2(tree, 24);
//	cout << find << endl;
//	return 0;
//}