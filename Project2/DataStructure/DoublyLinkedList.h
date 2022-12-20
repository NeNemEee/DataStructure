#pragma once

/*
* 크기가 가변적
* Singly LinkedList 보다 빠른 탐색 가능(기존에는 앞방향부터 탐색하던걸 위치에 따라 뒷방향 부터 탐색 가능)
*
* 데이터 삭제시 데이터 연결 재구성
* 포인터를 위한 별도의 저장공간이 필요
* Singly LinkedList 보다 더 많이 필요
* 탐색시 O(n)
*/
template <typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();

public:
	void Pushback(const T& data);
	void PushFront(const T& data);
	void Insert(const T& data, const UINT& idx);

	void PopBack();
	void PopFront();
	void Delete(const UINT& idx);

	T At(const UINT& idx);

	UINT GetLength() const { return length; };
	bool Check(UINT idx);

private:
	UINT length = 0;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;

};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	first->isDelete = true;
	delete first;
	first = nullptr;

	last = nullptr;
}

template<typename T>
inline void DoublyLinkedList<T>::Pushback(const T& data)
{
	if (length == 0) {
		first = new Node<T>(data);
		last = first;
		length++;

		return;
	}

	Node<T>* temp = new Node<T>(data);
	last->next = temp;
	temp->prev = last;
	last = temp;
	length++;

	return;
}

template<typename T>
inline void DoublyLinkedList<T>::PushFront(const T& data)
{
	if (length == 0) {
		first = new Node<T>(data);
		last = first;
		length++;

		return;
	}

	Node<T>* temp = new Node<T>(data);
	first->prev = temp;
	temp->next = first;
	first = temp;
	length++;

	return;
}

template<typename T>
inline void DoublyLinkedList<T>::Insert(const T& data, const UINT& idx)
{
	if (!Check(idx)) {
		printf("Insert Fail\n");
		return;
	}
	Node<T>* node = nullptr;
	if (length / 2 > idx) {
		node = first;
		for (UINT i = 0; i < idx; i++) {
			node = node->next;
		}
	}
	else {
		node = last;
		for (UINT i = length - 1; i > idx; i--) {
			node = node->prev;
		}
	}

	Node<T>* temp = node->next;
	Node<T>* tempp = node->prev;
	Node<T>* temppp = new Node<T>(data);
	temppp->prev = tempp;
	temppp->next = temp;
	node->next = temppp;
	length++;

	return;
}

template<typename T>
inline void DoublyLinkedList<T>::PopBack()
{
	if (length == 0) {
		printf("Empty\n");
		return;
	}

	if (length == 1) {
		delete first;
		first = nullptr;
		last = nullptr;

		return;
	}

	Node<T>* node = last->prev;
	node->next = nullptr;
	delete last;
	last = node;
	length--;

	return;
}

template<typename T>
inline void DoublyLinkedList<T>::PopFront()
{
	if (length == 0) {
		printf("Empty\n");
		return;
	}

	if (length == 1) {
		delete first;
		first = nullptr;
		last = nullptr;

		return;
	}

	Node<T>* node = first->next;
	node->prev = nullptr;
	delete first;
	first = node;
	length--;

	return;
}

template<typename T>
inline void DoublyLinkedList<T>::Delete(const UINT& idx)
{
	if (!Check(idx)) {
		printf("Delete Fail\n");
		return;
	}

	Node<T>* node = nullptr;
	if (length / 2 > idx) {
		node = first;
		for (UINT i = 0; i < idx; i++) {
			node = node->next;
		}
	}
	else {
		node = last;
		for (UINT i = length - 1; i > idx; i--) {
			node = node->prev;
		}
	}

	Node<T>* tempPrev = node->prev;
	Node<T>* tempNext = node->next;
	tempPrev->next = tempNext;
	tempNext->prev = tempPrev;

	delete node;
	node = nullptr;
	length--;
	
	return;
}

template<typename T>
inline T DoublyLinkedList<T>::At(const UINT& idx)
{
	if (!Check(idx)) {
		printf("At Fail\n");
		return 0;
	}

	Node<T>* node = nullptr;
	if (length / 2 > idx) {
		node = first;
		for (UINT i = 0; i < idx; i++) {
			node = node->next;
		}
	}
	else {
		node = last;
		for (UINT i = length - 1; i > idx; i--) {
			node = node->prev;
		}
	}

	return node->data;
}

template<typename T>
inline bool DoublyLinkedList<T>::Check(UINT idx)
{
	if (idx < 0 || idx >= length) {
		return false;
	}
	return true;
}
