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
//struct element {//�������
//	int weight;  //�ַ����ֵĸ���Ϊʵ��  
//	int lchild, rchild, parent;
//};
//
//void Select(element huffTree[], int *a, int *b, int n) {//��HuffTer����Ȩֵ��С���������i1��i2  
//	int i;
//	int weight = 0;
//	for (i = 0; i < n; i++) {
//		if (huffTree[i].parent != -1)       //����и����ģ��������ж�  
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
//		if (huffTree[i].parent != -1 || (i == *a))//�ٴβ���һ���ڶ�С�� 
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
//	if (*a > *b) {//����һ���Ĺ������� 
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//}
//
//void HuffmanTree(element huffTree[], int w[], int n) {//����huffman��  
//	for (int i = 0; i < 2 * n - 1; i++) {//huffman������2*n - 1�����  ��ʼ��
//		huffTree[i].parent = -1;    //˫�׽��  
//		huffTree[i].lchild = -1;    //���ӽ��  
//		huffTree[i].rchild = -1;    //�Һ��ӽ��  
//	}
//	for (int i = 0; i < n; i++) {      //����n��ֻ���и����Ķ�����  ��Ȩֵ
//		huffTree[i].weight = w[i];  //��huffman����Ȩֵ  
//	}
//	for (int k = n; k < 2 * n - 1; k++) {//n-1�κϲ�  
//		int i1 = 0;
//		int i2 = 0;
//		Select(huffTree, &i1, &i2, k); //��HuffTer����Ȩֵ��С���������i1��i2  
//		huffTree[i1].parent = k;    //��i1��i2�ϲ�����i1��i2��˫����k  
//		huffTree[i2].parent = k;
//		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
//		huffTree[k].lchild = i1;
//		huffTree[k].rchild = i2;
//	}
//}
//
//void HuffmanCode(element huffTree[], int n) {//huffman����  
//	int i, j, p, lc;
//	string s = "";
//	for (i = 0; i < n; i++) {  //������HuffTree��ǰn��Ԫ����Ҷ�ӽ�㣬��Ҫ����  
//		s = "";         //����s��ʼ��Ϊ�մ�  
//		j = i;                  //�ݴ�i�����ƻ�ѭ������  
//		while (huffTree[j].parent != -1) {//���j����˫��  
//			p = huffTree[j].parent;
//			lc = huffTree[p].lchild;
//			if (j == lc) s = s + "0";		 //���j����˫�׵����� 
//			else s = s + "1";
//			j = huffTree[j].parent; //�����j��˫�׸���j  
//		}
//		for (int i = s.size() - 1; i >= 0; i--)//��s��Ϊ���i�ı����������
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
//		HuffmanTree(huffTree, w, n);// ����huffman��
//		HuffmanCode(huffTree, n);//����
//	}
//	return 0;
//}
//
////void outputhuffmantree(element h[], int n) {
////	for (int i = 0; i < n; i++)
////		cout <<"w:"<< h[i].weight << " p:" << h[i].parent << " " << endl;
////	for (int i = n; i < 2 * n - 1; i++)//n-1�κϲ�  
////		cout << "w:" << h[i].weight << " lc:" << h[i].lchild
////		<< " rc:" << h[i].rchild << " p:" << h[i].parent << " " << endl;
////}
//
//////C++ʵ��
//
////#include<stdio.h>
////#include<stdlib.h>
////#include<string>
//////haffman ���Ľṹ
////typedef struct
////{
////	//Ҷ�ӽ��Ȩֵ
////	unsigned int weight;
////	//ָ��˫�ף��ͺ��ӽ���ָ��
////	unsigned int parent;
////	unsigned int lChild;
////	unsigned int rChild;
////} Node, *HuffmanTree;
////
//////��̬�������飬�洢����������
////typedef char *HuffmanCode;
////
//////ѡ������parentΪ0����weight��С�Ľ��s1��s2�ķ���ʵ��
//////n ΪҶ�ӽ���������s1�� s2����ָ�����ָ��Ҫѡȡ����������Ȩֵ��С�Ľ��
////void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2)
////{
////	//��� i
////	int i = 0;
////	//��¼��СȨֵ
////	int min;
////	//����ȫ����㣬�ҳ����ڵ�
////	for (i = 1; i <= n; i++)
////	{
////		//����˽��ĸ���û�У���ô�ѽ��Ÿ�ֵ�� min������ѭ��
////		if ((*huffmanTree)[i].parent == 0)
////		{
////			min = i;
////			break;
////		}
////	}
////	//��������ȫ����㣬�ҳ�Ȩֵ��С�ĵ��ڵ�
////	for (i = 1; i <= n; i++)
////	{
////		//����˽��ĸ���Ϊ�գ������ if
////		if ((*huffmanTree)[i].parent == 0)
////		{
////			//����˽���Ȩֵ�� min ����ȨֵС����ô���� min ��㣬��������ʼ�� min
////			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
////			{
////				min = i;
////			}
////		}
////	}
////	//�ҵ�����СȨֵ�Ľ�㣬s1ָ��
////	*s1 = min;
////	//����ȫ�����
////	for (i = 1; i <= n; i++)
////	{
////		//�ҳ���һ�����ڵ㣬��û�б� s1ָ����ôi ��ֵ�� min������ѭ��
////		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
////		{
////			min = i;
////			break;
////		}
////	}
////	//��������ȫ����㣬�ҵ�Ȩֵ��С����һ��
////	for (i = 1; i <= n; i++)
////	{
////		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
////		{
////			//����˽���Ȩֵ�� min ����ȨֵС����ô���� min ��㣬��������ʼ�� min
////			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
////			{
////				min = i;
////			}
////		}
////	}
////	//s2ָ��ָ��ڶ���Ȩֵ��С��Ҷ�ӽ��
////	*s2 = min;
////	if (*s1 > *s2) {
////		int temp = *s1;
////		*s1 = *s2;
////		*s2 = temp;
////	}
////}
////
//////���������������������������㷨���£�w��������֪��n��Ȩֵ
////void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
////{
////	//m Ϊ���������ܹ��Ľ������n ΪҶ�ӽ����
////	int m = 2 * n - 1;
////	//s1 �� s2 Ϊ������ǰ����Ҫѡȡ����СȨֵ�Ľ��
////	int s1;
////	int s2;
////	//���
////	int i;
////	// �������������Ľ������Ŀռ䣬m+1���������а���һ��ͷ���
////	*huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
////	//1--n�Ŵ��Ҷ�ӽ�㣬��ʼ��Ҷ�ӽ�㣬�ṹ��������ʼ��ÿ��Ҷ�ӽ�㣬��ʼ��ʱ����һ�����������Ķ�����
////	for (i = 1; i <= n; i++)
////	{
////
////		//����Ҷ�ӽ���Ȩֵ�� w��n������������
////		(*huffmanTree)[i].weight = w[i];
////		//��ʼ��Ҷ�ӽ�㣨���������������ĺ��Ӻ�˫�ף�������㣬Ҳ����û�к��Ӻ�˫�ף�==0
////		(*huffmanTree)[i].lChild = 0;
////		(*huffmanTree)[i].parent = 0;
////		(*huffmanTree)[i].rChild = 0;
////	}// end of for
////	 //��Ҷ�ӽ��ĳ�ʼ��
////	for (i = n + 1; i <= m; i++)
////	{
////		(*huffmanTree)[i].weight = 0;
////		(*huffmanTree)[i].lChild = 0;
////		(*huffmanTree)[i].parent = 0;
////		(*huffmanTree)[i].rChild = 0;
////	}
////
////	//printf("\n HuffmanTree: \n");
////	//������Ҷ�ӽ�㣬����������
////	for (i = n + 1; i <= m; i++)
////	{
////		//��(*huffmanTree)[1]~(*huffmanTree)[i-1]�ķ�Χ��ѡ������parentΪ0
////		//��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2
////		select(huffmanTree, i - 1, &s1, &s2);
////		//ѡ��������Ȩֵ��С��Ҷ�ӽ�㣬���һ���µĶ���������Ϊ i ���
////		(*huffmanTree)[s1].parent = i;
////		(*huffmanTree)[s2].parent = i;
////		(*huffmanTree)[i].lChild = s1;
////		(*huffmanTree)[i].rChild = s2;
////		//�µĽ�� i ��Ȩֵ
////		(*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight;
////
////		//printf("%d (%d, %d)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
////	}
////
////	//printf("\n");
////}
////
//////��������������ϣ��� n ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
////void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
////{
////	//ָʾbiaoji
////	int i;
////	//�������ʼָ��
////	int start;
////	//ָ��ǰ���ĸ��ڵ�
////	int p;
////	//���� n ��Ҷ�ӽ���ָʾ��� c
////	unsigned int c;
////	//����n�������ͷָ��
////	huffmanCode = (HuffmanCode *)malloc((n + 1) * sizeof(char *));
////	//������ǰ����Ĺ����ռ�
////	char *cd = (char *)malloc(n * sizeof(char));
////	//����������λ��ű��룬���ȴ�ű��������
////	cd[n - 1] = '\0';
////	//��n��Ҷ�ӽ���Ӧ�Ĺ���������
////	for (i = 1; i <= n; i++)
////	{
////		//��ʼ��������ʼָ��
////		start = n - 1;
////		//��Ҷ�ӵ�����������
////		for (c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
////		{
////			if ((*huffmanTree)[p].lChild == c)
////			{
////				//���ҵ����˳�������������
////				cd[--start] = '0';  //���֧��0
////			}
////			else
////			{
////				cd[--start] = '1';  //�ҷ�֧��1
////			}
////		}// end of for
////		 //Ϊ��i���������ռ�
////		huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));
////
////		strcpy(huffmanCode[i], &cd[start]);
////	}
////
////	free(cd);
////	//��ӡ��������
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
