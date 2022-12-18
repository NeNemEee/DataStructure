#pragma once
/*
* 데이터와 포인터주소의 쌍으로 구성됨
* 단방향 LinkedList 일 경우 포인터값 1개
* 양방향일 경우 포인터값 2개
*/
template <typename T>
class Node {
public:
	Node(T data);
	~Node();

	T data;
	Node<T>* next;
	bool isDelete = false;
};

template<typename T>
inline Node<T>::Node(T data)
{
	this->data = data;
	next = nullptr;
}

template<typename T>
inline Node<T>::~Node()
{
	cout << data << endl;
	if (isDelete && next != nullptr) {
		next->isDelete = isDelete;
		delete next;
		next = nullptr;
	}
}


