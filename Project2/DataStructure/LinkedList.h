#pragma once
/*
* 크기가 가변적
* 
* 데이터 삭제시 데이터 연결 재구성
* 포인터를 위한 별도의 저장공간이 필요
* 탐색시 O(n)
*/
template <typename T>
class LinkedList {
public:
	LinkedList(T data);
	~LinkedList();

public:
	void Add(T data);
	void Add(UINT idx, T data);
	void Delete(UINT idx);
	T& GetData(UINT idx);
	void AllPrint();
	bool Check(UINT idx);

private:
	UINT length = 0;
	Node<T>* first = nullptr;

};

template<typename T>
inline LinkedList<T>::LinkedList(T data)
{
	first = new Node<T>(data);
	length++;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	if (first != nullptr) {
		first->isDelete = true;
		delete first;
		first = nullptr;
	}
}

template<typename T>
inline void LinkedList<T>::Add(T data)
{
	if (length == 0) {
		first = new Node<T>(data);
		length++;
		return;
	}

	Node<T>* temp = first;
	while (true) {
		if (temp->next == nullptr) {
			break;
		}

		temp = temp->next;
	}

	Node<T>* tempp = new Node<T>(data);
	temp->next = tempp;
	length++;
}

template<typename T>
inline void LinkedList<T>::Add(UINT idx, T data)
{

	if (length == 0) {
		first = new Node<T>(data);
		length++;
		return;
	}

	if (!Check(idx)) {
		return;
	}

	Node<T>* temp = first;
	for (int i = 0; i < idx; i++) {
		temp = temp->next;
	}

	if (temp->next != nullptr) {
		Node<T>* tempp = temp->next;
		Node<T>* temppp = new Node<T>(data);
		temppp->next = tempp;
		temp->next = temppp;
	}
	else {
		Node<T>* tempp = new Node<T>(data);
		temp->next = tempp;
	}

	length++;
}

template<typename T>
inline void LinkedList<T>::Delete(UINT idx)
{
	if (!Check(idx)) {
		return;
	}

	Node<T>* temp = first;
	for (int i = 0; i < idx - 1; i++) {
		temp = temp->next;
	}

	Node<T>* tempp = temp->next->next;
	temp->next->isDelete = false;
	delete temp->next;
	temp->next = tempp;
	length--;
}

template<typename T>
inline T& LinkedList<T>::GetData(UINT idx)
{
	if (!Check(idx)) {
		return nullptr;
	}
	Node<T>* temp = first;
	for (UINT i = 0; i < idx; i++) {
		temp = temp->next;
	}

	return temp->data;
}



template<typename T>
inline void LinkedList<T>::AllPrint()
{
	Node<T>* temp = first;
	for (int i = 0; i < length; i++) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

template<typename T>
inline bool LinkedList<T>::Check(UINT idx)
{
	if (idx < 0 || idx >= length) {
		return false;
	}
	return true;
}
