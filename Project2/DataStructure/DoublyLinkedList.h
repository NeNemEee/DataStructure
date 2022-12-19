#pragma once

/*
* 크기가 가변적
*
* 데이터 삭제시 데이터 연결 재구성
* 포인터를 위한 별도의 저장공간이 필요
* 탐색시 O(n)
*/
template <typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();

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

