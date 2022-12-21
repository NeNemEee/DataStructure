#pragma once

template <typename T>
class Queue {
public:
	Queue();
	~Queue();

public:
	void Push(const T& data);
	void Pop();

	T Front();
	T Rear();

	bool Empty();

private:
	UINT capacity = 0;
	UINT front = 0;
	UINT rear = 0;

	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
};

template<typename T>
inline Queue<T>::Queue()
{
}

template<typename T>
inline Queue<T>::~Queue()
{
	if (first != nullptr) {
		first->isDelete = true;
		delete first;
		first = nullptr;
		last = nullptr;
	}
}

template<typename T>
inline void Queue<T>::Push(const T& data)
{
	if (Empty()) {
		first = new Node<T>(data);
		last = first;
		capacity++;

		return;
	}

	if (capacity == 1) {
		first = new Node<T>(data);
		first->next = last;
		last->prev = first;
		capacity++;

		return;
	}

	Node<T>* node = new Node<T>(data);
	node->next = first;
	first->prev = node;
	first = node;
	capacity++;

	return;
}

template<typename T>
inline void Queue<T>::Pop()
{
	if (Empty()) {
		printf("data 0\n");
		return;
	}

	if (capacity == 1) {
		delete first;
		first = nullptr;
		last = nullptr;
		capacity--;

		return;
	}

	Node<T>* node = last->prev;
	delete last;
	last = node;
	capacity--;

	return;
}

template<typename T>
inline T Queue<T>::Front()
{
	if (Empty()) {
		printf("data 0 \n");
		return 0;
	}

	return first->data;
}

template<typename T>
inline T Queue<T>::Rear()
{
	if (Empty()) {
		printf("data 0\n");
		return 0;
	}

	return last->data;
}

template<typename T>
inline bool Queue<T>::Empty()
{
	if (capacity == 0) {
		return true;
	}
	return false;
}
