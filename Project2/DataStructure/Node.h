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
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
	bool isDelete = false; // LinkedList ��ü ���� �� ���� ���� �����ؼ� ������ �Ǻ��ϴ� bool ����
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
	if (isDelete && next != nullptr) {
		next->isDelete = true;
		delete next;
		next = nullptr;
		prev = nullptr;
	}
}


