#pragma once

/*
* ũ�Ⱑ ������
*
* ������ ������ ������ ���� �籸��
* �����͸� ���� ������ ��������� �ʿ�
* Ž���� O(n)
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

