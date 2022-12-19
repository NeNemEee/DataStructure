#pragma once
/*
* 크기가 가변적
* 선형구조
* 구조 변경시 효율성이 좋음
* 
* 데이터 삭제시 데이터 연결 재구성
* 포인터를 위한 별도의 저장공간이 필요
* 탐색시 O(n)
* 
* ex)브라우저의 뒤로가기 앞으로가기 등
*/
template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

public:
	void Pushback(const T& data);
	void Insert(const T& data, const UINT& idx);

	void PopBack();
	void Delete(const UINT& idx);

	T At(const UINT& idx);

	UINT GetLength() const { return length; };
	bool Check(UINT idx);

private:
	UINT length = 0;
	Node<T>* first = nullptr;

};

template<typename T>
inline LinkedList<T>::LinkedList()
{
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
inline void LinkedList<T>::Pushback(const T& data)
{
	if (first == nullptr) {
		first = new Node<T>(data);
		first->data = data;
		length++;
		return;
	}

	Node<T>* node = first;
	for (UINT i = 0; i < length-1; i++) {
		node = node->next;
	}
	node->next = new Node<T>(data);
	length++;

	return;
}

template<typename T>
inline void LinkedList<T>::Insert(const T& data, const UINT& idx)
{
	if (!Check(idx)) {
		printf("Insert Fail\n");
		return;
	}

	Node<T>* node = first;
	for (UINT i = 0; i < idx; i++) {
		node = node->next;
	}

	Node<T>* temp = node->next;
	Node<T>* tempp = new Node<T>(data);
	tempp->data = data;
	tempp->next = temp;
	node->next = tempp;
	length++;

	return;
}

template<typename T>
inline void LinkedList<T>::PopBack()
{
	if (first == nullptr) {
		printf("Pop Fail\n");
		return;
	}

	if (length == 1) {
		delete first;
		first = nullptr;
		length = 0;

		return;
	}

	Node<T>* node = first;
	for (UINT i = 0; i < length-1; i++) {
		node = node->next;
	}

	Node<T>* temp = node->next;
	delete temp;
	temp = nullptr;
	node->next = nullptr;
	length--;

	return;
}

template<typename T>
inline void LinkedList<T>::Delete(const UINT& idx)
{
	if (!Check(idx)) {
		printf("Delete Fail\n");
		return;
	}

	Node<T>* node = first;
	for (UINT i = 0; i < idx - 2; i++) {
		node = node->next;
	}
	Node<T>* temp = node->next->next;
	Node<T>* tempp = node->next;
	delete tempp;
	tempp = nullptr;
	node->next = temp;
	length--;

	return;
}

template<typename T>
inline T LinkedList<T>::At(const UINT& idx)
{
	if (!Check(idx)) {
		printf("At Fail\n");
		return 1;
	}

	Node<T>* node = first;
	for (UINT i = 0; i < idx; i++) {
		node = node->next;
	}

	return node->data;
	
}

template<typename T>
inline bool LinkedList<T>::Check(UINT idx)
{
	if (idx < 0 || idx >= length) {
		return false;
	}
	return true;
}
