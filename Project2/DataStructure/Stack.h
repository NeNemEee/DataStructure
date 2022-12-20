#pragma once
template <typename T>
class Stack {
public:
	Stack();
	~Stack();

public:
	void Push(T data);
	void Pop();

	void Print();
	
	T Top();
	UINT Size();
	bool IsEmpty();

private:
	UINT capacity = 0;
	Node<T>* node = nullptr;
};

template<typename T>
inline Stack<T>::Stack()
{
}

template<typename T>
inline Stack<T>::~Stack()
{
	if (capacity != 0) {
		node->isDelete = true;
		delete node;
		node = nullptr;
	}
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	Node<T>* temp = new Node<T>(data);
	temp->next = node;
	node = temp;
	capacity++;

	return;
}

template<typename T>
inline void Stack<T>::Pop()
{
	if (IsEmpty())
		return;

	Node<T>* temp = node->next;
	delete node;
	node = temp;
	capacity--;

	return;

}

template<typename T>
inline void Stack<T>::Print()
{
	Node<T>* temp = node;
	while (true) {
		if (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
		else {
			break;
		}
	}
}

template<typename T>
inline T Stack<T>::Top()
{
	return node->data;
}

template<typename T>
inline UINT Stack<T>::Size()
{
	return capacity;
}

template<typename T>
inline bool Stack<T>::IsEmpty()
{
	if (capacity == 0) {
		return true;
	}
	return false;
}
