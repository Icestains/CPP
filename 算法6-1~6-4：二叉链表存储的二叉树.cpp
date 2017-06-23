//#include <iostream>
//#include <cstdlib>
//#include <stack>
//#include <deque>
//using namespace std;
//
//
//template<class T>
//struct BinTreeNode  //�������ڵ���Ķ��壬ʹ�ö�������
//{
//	T data;
//	BinTreeNode<T> *leftChild, *rightChild;
//	BinTreeNode() :leftChild(NULL), rightChild(NULL) {}
//	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :data(x), leftChild(l), rightChild(r) {}
//};
//
////��������ģ����ʵ�����£��ɽ�����Ӧ�Ĺ�����չ��
////�ӿڲ��֣�
//template<class T>
//class BinaryTree//��������ģ����
//{
//public:
//	BinaryTree() :root(NULL) {}
//	BinaryTree(char x) :root(NULL), RefValue(x) {}
//	BinaryTree(const BinaryTree<T>& rhs) { root = copy(rhs.root); }//copy���캯��
//	BinaryTree<T>& operator=(const BinaryTree<T>& rhs);//copy ��ֵ�����;����+copy���캯��  
//	~BinaryTree() { destroy(root); }//��������
//
//	bool isEmpty()const { return root != NULL ? false : true; }
//	BinTreeNode<T>* leftChild(BinTreeNode<T>* current)const { return current != NULL ? current->leftChild : NULL; }
//	BinTreeNode<T>* rightChild(BinTreeNode<T>* current)const { return current != NULL ? current->rightChild : NULL; }
//	BinTreeNode<T>* parent(BinTreeNode<T>* current)const { return (root == NULL || current == root) ? NULL : parent(root, current); }//Ѱ���丸�ڵ�
//	BinTreeNode<T>* getRoot()const { return root; }
//
//	void inOrder(void(*visit)(BinTreeNode<T> *p)) { inOrder(root, visit); }//����ݹ����
//	void preOrder(void(*visit)(BinTreeNode<T> *p)) { preOrder(root, visit); }//ǰ��ݹ�
//	void postOrder(void(*visit)(BinTreeNode<T> *p)) { postOrder(root, visit); }//����ݹ�
//	void levelOrder(void(*visit)(BinTreeNode<T> *p));//ʹ�ö��еĲ�α���
//
//	int size()const { return size(root); }//ʹ�ú���ݹ������ڵ����
//	int height()const { return height(root); }//ʹ�ú���ݹ������������ĸ߶�
//
//
//
//protected:
//	BinTreeNode<T> *root;
//	char RefValue;//��������ֹͣ��־
//
//	void destroy(BinTreeNode<T>* subTree);//�ݹ�ɾ���������ڵ㣬�������ɾ��
//	BinTreeNode<T>* copy(const BinTreeNode<T> *orignode);//copy����;ǰ��
//
//	BinTreeNode<T>* parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current)const;//���ظ��ڵ�
//	void traverse(BinTreeNode<T>* subTree, ostream& out)const;//��ǰ��ʽ�������ÿ���ڵ��ֵ
//	void createBinTree(istream& in, BinTreeNode<T>* & subTree);//���ù�����ʾ�Ķ�������������
//
//	void inOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p));//�������
//	void preOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p));//ǰ�����
//	void postOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p));//�������
//
//	int size(BinTreeNode<T> *subTree)const;//ʹ�ú���ݹ������ڵ����
//	int height(BinTreeNode<T> *subTree)const;//ʹ�ú���ݹ������������ĸ߶�
//
//
//	friend ostream& operator<< <T>(ostream& out, const BinaryTree<T>& rhs);//add <T> ǰ�����������
//	friend istream& operator>> <T>(istream& in, BinaryTree<T>& rhs);      //add <T> ���ù�����ʾ��ʽ����������
//
//};
//
////��Ӧ��Ա�����ľ���ʵ�֣�
//
//template<class T>
//void BinaryTree<T>::destroy(BinTreeNode<T>* subTree)
//{
//	if (subTree != NULL) {
//		destroy(subTree->leftChild);
//		destroy(subTree->rightChild);
//		delete subTree;
//	}
//}
//
//template<class T>
//BinTreeNode<T>* BinaryTree<T>::parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current)const
//{
//	if (subTree == NULL) return NULL;
//	if (subTree->leftChild == current || subTree->rightChild == current) return subTree;
//
//	BinTreeNode<T>* p;
//	if ((p = parent(subTree->leftChild, current)) != NULL)
//		return p
//	else
//		return parent(subTree->rightChild, current);
//}
//
//template<class T>
//void BinaryTree<T>::traverse(BinTreeNode<T>* subTree, ostream& out)const
//{
//	if (subTree != NULL) {
//		out << subTree->data << " ";
//		traverse(subTree->leftChild, cout);
//		traverse(subTree->rightChild, out);
//	}
//}
//
//template<class T>
//void BinaryTree<T>::createBinTree(istream& in, BinTreeNode<T>* & subTree)
//{
//	stack<BinTreeNode<T>* > s;
//	subTree = NULL;
//	BinTreeNode<T> *p, *t;
//	unsigned int k;
//	T ch;
//	in >> ch;//��Ȼ��ģ���࣬����Ŀǰֻ֧���ַ��ͣ���Ȼ�ᱨ��
//	while (ch != RefValue) {
//		switch (ch) {
//		case '(': s.push(p); k = 1; break;
//		case ')': s.pop(); break;
//		case ',': k = 2; break;
//		default:
//			p = new BinTreeNode<T>(ch);
//			if (subTree == NULL)
//				subTree = p;
//			else if (k == 1)
//			{
//				t = s.top(); t->leftChild = p;
//			}
//			else
//			{
//				t = s.top(); t->rightChild = p;
//			}
//		}
//		in >> ch;
//	}
//}
//
//template<class T>
//ostream& operator<<(ostream& out, const BinaryTree<T>& rhs)
//{
//	rhs.traverse(rhs.root, out);
//	out << endl;
//	return out;
//}
//
//template<class T>
//istream& operator>>(istream& in, BinaryTree<T>& rhs)
//{
//	rhs.createBinTree(in, rhs.root);
//	return in;
//}
//
//template<class T>
//void BinaryTree<T>::inOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p))
//{
//	if (subTree != NULL) {
//		inOrder(subTree->leftChild, visit);
//		visit(subTree);
//		inOrder(subTree->rightChild, visit);
//	}
//}
//
//template<class T>
//void BinaryTree<T>::preOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p))
//{
//	if (subTree != NULL) {
//		visit(subTree);
//		inOrder(subTree->leftChild, visit);
//		inOrder(subTree->rightChild, visit);
//	}
//}
//
//template<class T>
//void BinaryTree<T>::postOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p))
//{
//	if (subTree != NULL) {
//		inOrder(subTree->leftChild, visit);
//		inOrder(subTree->rightChild, visit);
//		visit(subTree);
//	}
//}
//
//template<class T>
//int BinaryTree<T>::size(BinTreeNode<T> *subTree)const
//{
//	if (subTree == NULL)  return 0;
//	else
//		return 1 + size(subTree->leftChild) + size(subTree->rightChild);
//}
//
//template<class T>
//int BinaryTree<T>::height(BinTreeNode<T> *subTree)const
//{
//	if (subTree == NULL) return 0;
//	else {
//		int i = height(subTree->leftChild);
//		int j = height(subTree->rightChild);
//		return (i>j) ? i + 1 : j + 1;
//	}
//}
//
//template<class T>
//BinTreeNode<T>* BinaryTree<T>::copy(const BinTreeNode<T> *orignode)
//{
//	if (orignode == NULL) return NULL;
//	BinTreeNode<T> *temp = new BinTreeNode<T>;
//	temp->data = orignode->data;
//	temp->leftChild = copy(orignode->leftChild);
//	temp->rightChild = copy(orignode->rightChild);
//	return temp;
//}
//
//template<class T>
//BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& rhs)
//{
//	this->destroy(this->root);
//	this->root = copy(rhs.root);
//	return *this;
//}
//
//template<class T>
//void BinaryTree<T>::levelOrder(void(*visit)(BinTreeNode<T> *p))
//{
//	deque<BinTreeNode<T>* > dq;
//	BinTreeNode<T> *p = root;
//	dq.push_back(p);
//	while (!dq.empty()) {
//		p = dq.front();
//		visit(p);
//		dq.pop_front();
//
//		if (p->leftChild != NULL) dq.push_back(p->leftChild);
//		if (p->rightChild != NULL) dq.push_back(p->rightChild);
//	}
//}
//
//
////���Ժ�����
//int main(int argc, char* argv[])
//{
//
//	BinaryTree<char> b('#');
//	cin >> b;
//	cout << b << endl;
//
//	//b.levelOrder(NULL);
//
//	//BinaryTree<char> a('#');
//	//cin>>a;
//	//cout<<a<<endl;
//	// b=a;
//	//cout<<b<<endl;
//
//	//BinaryTree<char> a=b;
//	//cout<<a<<endl;
//
//	//cout<<b.size()<<endl;
//	//cout<<b.isEmpty()<<endl;
//	//cout<<b.height()<<endl;
//
////	system("pause");
//	return 0;
//
//}
