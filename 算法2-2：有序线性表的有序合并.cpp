//#include <iostream>
//using namespace std;
//
//#define defaultsize 100
//
//template<class T>
//struct LinkNode {
//	int data;
//	LinkNode<T> *link;
//	LinkNode(LinkNode<T> *ptr = NULL) { link = ptr; }
//	LinkNode(const T& item, LinkNode<T> *ptr = null) {
//		data = item;
//		link = ptr;
//	}
//};
//
//template <class T >
//class List {
//public:
//	List() { first = new LinkNode<T>; }
//	List(const T& x) { first = new LinkNode<T>(x); }
//	List(List<T>& T);
//	~List() { makeEmpty(); }
//	void makeEmpty();
//
//
//	void input();
//	void output();
//};
//
//template<class T>
//List<T>::List(List<T>& L) {
//	
//}
//
//template<class T>
//void List<T>::makeEmpty() {
//	LinkNode<T> *q;
//	while (first->link != null) {
//		q = first->link;
//		first-> = q->link;
//		delete p;
//	}
//}
//
//template<class T>
//void List<T>::input() {
//	LinkNode *c = first->link;
//	cin >> n;
//	while (n--) {
//		cin >> c->data;
//		c = c->link;
//	}
//}
//
//template<class T>
//void List<T>::output() {
//	LinkNode *c = first->link;
//	cout << c->data;
//	while (c != NULL) {
//		cout << " " << c->data;
//		c = c->link;
//	}
//}
//
