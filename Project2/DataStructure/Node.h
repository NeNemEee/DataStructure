#pragma once
/*
* �����Ϳ� �������ּ��� ������ ������
* �ܹ��� LinkedList �� ��� �����Ͱ� 1��
* ������� ��� �����Ͱ� 2��
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


