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
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
	bool isDelete = false; // LinkedList 전체 삭제 시 다음 것을 연속해서 지울지 판별하는 bool 변수
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


