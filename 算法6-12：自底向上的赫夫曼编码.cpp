#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct htnode
{
	int weight;
	int left;
	int right;
	int parent;
};
struct hcode
{
	char code[15];
	int start;
};
htnode h[200];
hcode cd[100];
void createht(htnode ht[], int n)
{
	int m = 2 * n - 1;
	int i, j;
	for (i = 0; i<m; i++)
		ht[i].parent = ht[i].left = ht[i].right = -1;
	int min1, min2;
	int lnode, rnode;
	for (i = n; i<m; i++)
	{
		min1 = min2 = 99999;
		lnode = rnode = -1;
		for (j = 0; j<i; j++)
			if (ht[j].weight<min1&&ht[j].parent == -1)
			{
				min1 = ht[j].weight;
				lnode = j;
			}
		ht[lnode].parent = i;
		for (j = 0; j<i; j++)
			if (ht[j].weight<min2&&ht[j].parent == -1)
			{
				min2 = ht[j].weight;
				rnode = j;
			}
		ht[rnode].parent = i;
		if (lnode>rnode)
		{
			int node;
			node = lnode; lnode = rnode; rnode = node;
		}
		ht[i].left = lnode;
		ht[i].right = rnode;
		ht[i].weight = min1 + min2;
	}
}
void createhcd(htnode ht[], hcode hcd[], int n)
{
	int i, j, k;
	char s[15];
	int top = 0;
	int lnode;
	for (i = 0; i<n; i++)
	{
		j = i;
		lnode = j;
		while (j != -1)
		{
			j = ht[j].parent;
			if (ht[j].left == lnode) s[top] = '0';
			else s[top] = '1';
			top++;
			lnode = j;
		}
		k = 0;
		top--;
		while (top>0)
		{
			top--;
			hcd[i].code[k] = s[top];
			k++;
		}
		puts(hcd[i].code);
		top = 0;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
			cin>>h[i].weight;
		createht(h, n);
		createhcd(h, cd, n);
	}
	return 0;
}

//#include<iostream> 
//#include<string>
//using namespace std;
//
//struct element {//结点类型
//	int weight;  //字符出现的概率为实数  
//	int lchild, rchild, parent;
//};
//
//void Select(element huffTree[], int *a, int *b, int n) {//在HuffTer中找权值最小的两个结点i1和i2  
//	int i;
//	int weight = 0;
//	for (i = 0; i < n; i++) {
//		if (huffTree[i].parent != -1)       //如果有父结点的，不进行判断  
//			continue;
//		else {
//			if (weight == 0) {
//				weight = huffTree[i].weight;
//				*a = i;
//			}
//			else {
//				if (huffTree[i].weight < weight) {
//					weight = huffTree[i].weight;
//					*a = i;
//				}
//			}
//		}
//	}
//	weight = 0;
//	for (i = 0; i < n; i++) {
//		if (huffTree[i].parent != -1 || (i == *a))//再次查找一个第二小的 
//			continue;
//		else {
//			if (weight == 0) {
//				weight = huffTree[i].weight;
//				*b = i;
//			}
//			else {
//				if (huffTree[i].weight < weight) {
//					weight = huffTree[i].weight;
//					*b = i;
//				}
//			}
//		}
//	}
//	if (*a > *b) {//按照一定的规则排序 
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//}
//
//void HuffmanTree(element huffTree[], int w[], int n) {//建立huffman树  
//	for (int i = 0; i < 2 * n - 1; i++) {//huffman树共有2*n - 1个结点  初始化
//		huffTree[i].parent = -1;    //双亲结点  
//		huffTree[i].lchild = -1;    //左孩子结点  
//		huffTree[i].rchild = -1;    //右孩子结点  
//	}
//	for (int i = 0; i < n; i++) {      //构造n棵只含有根结点的二叉树  赋权值
//		huffTree[i].weight = w[i];  //给huffman树赋权值  
//	}
//	for (int k = n; k < 2 * n - 1; k++) {//n-1次合并  
//		int i1 = 0;
//		int i2 = 0;
//		Select(huffTree, &i1, &i2, k); //在HuffTer中找权值最小的两个结点i1和i2  
//		huffTree[i1].parent = k;    //将i1和i2合并，则i1和i2的双亲是k  
//		huffTree[i2].parent = k;
//		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
//		huffTree[k].lchild = i1;
//		huffTree[k].rchild = i2;
//	}
//}
//
//void HuffmanCode(element huffTree[], int n) {//huffman编码  
//	int i, j, p, lc;
//	string s = "";
//	for (i = 0; i < n; i++) {  //在数组HuffTree中前n个元素是叶子结点，需要编码  
//		s = "";         //编码s初始化为空串  
//		j = i;                  //暂存i，不破坏循环变量  
//		while (huffTree[j].parent != -1) {//结点j存在双亲  
//			p = huffTree[j].parent;
//			lc = huffTree[p].lchild;
//			if (j == lc) s = s + "0";		 //结点j是其双亲的左孩子 
//			else s = s + "1";
//			j = huffTree[j].parent; //将结点j的双亲赋给j  
//		}
//		for (int i = s.size() - 1; i >= 0; i--)//将s作为结点i的编码逆序输出
//			cout << s.at(i);
//		cout << endl;
//	}
//}
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		element huffTree[205];
//		int w[205] = { 0 };
//		for (int i = 0; i < n; i++)
//			cin >> w[i];
//
//		HuffmanTree(huffTree, w, n);// 构造huffman树
//		HuffmanCode(huffTree, n);//编码
//	}
//	return 0;
//}
//
////void outputhuffmantree(element h[], int n) {
////	for (int i = 0; i < n; i++)
////		cout <<"w:"<< h[i].weight << " p:" << h[i].parent << " " << endl;
////	for (int i = n; i < 2 * n - 1; i++)//n-1次合并  
////		cout << "w:" << h[i].weight << " lc:" << h[i].lchild
////		<< " rc:" << h[i].rchild << " p:" << h[i].parent << " " << endl;
////}
//
//////C++实现
//
////#include<stdio.h>
////#include<stdlib.h>
////#include<string>
//////haffman 树的结构
////typedef struct
////{
////	//叶子结点权值
////	unsigned int weight;
////	//指向双亲，和孩子结点的指针
////	unsigned int parent;
////	unsigned int lChild;
////	unsigned int rChild;
////} Node, *HuffmanTree;
////
//////动态分配数组，存储哈夫曼编码
////typedef char *HuffmanCode;
////
//////选择两个parent为0，且weight最小的结点s1和s2的方法实现
//////n 为叶子结点的总数，s1和 s2两个指针参数指向要选取出来的两个权值最小的结点
////void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2)
////{
////	//标记 i
////	int i = 0;
////	//记录最小权值
////	int min;
////	//遍历全部结点，找出单节点
////	for (i = 1; i <= n; i++)
////	{
////		//如果此结点的父亲没有，那么把结点号赋值给 min，跳出循环
////		if ((*huffmanTree)[i].parent == 0)
////		{
////			min = i;
////			break;
////		}
////	}
////	//继续遍历全部结点，找出权值最小的单节点
////	for (i = 1; i <= n; i++)
////	{
////		//如果此结点的父亲为空，则进入 if
////		if ((*huffmanTree)[i].parent == 0)
////		{
////			//如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
////			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
////			{
////				min = i;
////			}
////		}
////	}
////	//找到了最小权值的结点，s1指向
////	*s1 = min;
////	//遍历全部结点
////	for (i = 1; i <= n; i++)
////	{
////		//找出下一个单节点，且没有被 s1指向，那么i 赋值给 min，跳出循环
////		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
////		{
////			min = i;
////			break;
////		}
////	}
////	//继续遍历全部结点，找到权值最小的那一个
////	for (i = 1; i <= n; i++)
////	{
////		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
////		{
////			//如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
////			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
////			{
////				min = i;
////			}
////		}
////	}
////	//s2指针指向第二个权值最小的叶子结点
////	*s2 = min;
////	if (*s1 > *s2) {
////		int temp = *s1;
////		*s1 = *s2;
////		*s2 = temp;
////	}
////}
////
//////创建哈夫曼树并求哈夫曼编码的算法如下，w数组存放已知的n个权值
////void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
////{
////	//m 为哈夫曼树总共的结点数，n 为叶子结点数
////	int m = 2 * n - 1;
////	//s1 和 s2 为两个当前结点里，要选取的最小权值的结点
////	int s1;
////	int s2;
////	//标记
////	int i;
////	// 创建哈夫曼树的结点所需的空间，m+1，代表其中包含一个头结点
////	*huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
////	//1--n号存放叶子结点，初始化叶子结点，结构数组来初始化每个叶子结点，初始的时候看做一个个单个结点的二叉树
////	for (i = 1; i <= n; i++)
////	{
////
////		//其中叶子结点的权值是 w【n】数组来保存
////		(*huffmanTree)[i].weight = w[i];
////		//初始化叶子结点（单个结点二叉树）的孩子和双亲，单个结点，也就是没有孩子和双亲，==0
////		(*huffmanTree)[i].lChild = 0;
////		(*huffmanTree)[i].parent = 0;
////		(*huffmanTree)[i].rChild = 0;
////	}// end of for
////	 //非叶子结点的初始化
////	for (i = n + 1; i <= m; i++)
////	{
////		(*huffmanTree)[i].weight = 0;
////		(*huffmanTree)[i].lChild = 0;
////		(*huffmanTree)[i].parent = 0;
////		(*huffmanTree)[i].rChild = 0;
////	}
////
////	//printf("\n HuffmanTree: \n");
////	//创建非叶子结点，建哈夫曼树
////	for (i = n + 1; i <= m; i++)
////	{
////		//在(*huffmanTree)[1]~(*huffmanTree)[i-1]的范围内选择两个parent为0
////		//且weight最小的结点，其序号分别赋值给s1、s2
////		select(huffmanTree, i - 1, &s1, &s2);
////		//选出的两个权值最小的叶子结点，组成一个新的二叉树，根为 i 结点
////		(*huffmanTree)[s1].parent = i;
////		(*huffmanTree)[s2].parent = i;
////		(*huffmanTree)[i].lChild = s1;
////		(*huffmanTree)[i].rChild = s2;
////		//新的结点 i 的权值
////		(*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight;
////
////		//printf("%d (%d, %d)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
////	}
////
////	//printf("\n");
////}
////
//////哈夫曼树建立完毕，从 n 个叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
////void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
////{
////	//指示biaoji
////	int i;
////	//编码的起始指针
////	int start;
////	//指向当前结点的父节点
////	int p;
////	//遍历 n 个叶子结点的指示标记 c
////	unsigned int c;
////	//分配n个编码的头指针
////	huffmanCode = (HuffmanCode *)malloc((n + 1) * sizeof(char *));
////	//分配求当前编码的工作空间
////	char *cd = (char *)malloc(n * sizeof(char));
////	//从右向左逐位存放编码，首先存放编码结束符
////	cd[n - 1] = '\0';
////	//求n个叶子结点对应的哈夫曼编码
////	for (i = 1; i <= n; i++)
////	{
////		//初始化编码起始指针
////		start = n - 1;
////		//从叶子到根结点求编码
////		for (c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
////		{
////			if ((*huffmanTree)[p].lChild == c)
////			{
////				//从右到左的顺序编码入数组内
////				cd[--start] = '0';  //左分支标0
////			}
////			else
////			{
////				cd[--start] = '1';  //右分支标1
////			}
////		}// end of for
////		 //为第i个编码分配空间
////		huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));
////
////		strcpy(huffmanCode[i], &cd[start]);
////	}
////
////	free(cd);
////	//打印编码序列
////	for (i = 1; i <= n; i++)
////	{
////		//printf("HuffmanCode of %3d is %s\n", (*huffmanTree)[i].weight, huffmanCode[i]);
////		printf("%s\n", huffmanCode[i]);
////	}
////
////	//printf("\n");
////}
////
////int main(void)
////{
////	HuffmanTree HT;
////	HuffmanCode HC;
////	int *w, i, n, wei;
////
////	//printf("\nn = ");
////
////	scanf("%d", &n);
////
////	w = (int *)malloc((n + 1) * sizeof(int));
////
////	//printf("\ninput the %d element's weight:\n", n);
////
////	for (i = 1; i <= n; i++)
////	{
////		//printf("%d: ", i);
////		fflush(stdin);
////		scanf("%d", &wei);
////		w[i] = wei;
////	}
////
////	createHuffmanTree(&HT, w, n);
////	creatHuffmanCode(&HT, &HC, n);
////
////	return 0;
////}
