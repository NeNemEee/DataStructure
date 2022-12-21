#include "Framework.h"

int main() {
	//Array* arr = new Array();

	//arr->SetLength(10);
	//arr->Print();
	//arr->Delete();
	//delete arr;

	//LinkedList<int>* list = new LinkedList<int>();
	//
	//for (UINT i = 0; i < 10; i++) {
	//	list->Pushback(i);
	//}
	//list->Delete(5);
	//list->Delete(6);
	//list->Insert(5, 5);
	//list->Insert(6, 6);
	//cout << "---------------------" << endl;
	//for (UINT i = 0; i < 10; i++) {
	//	cout<<list->At(i)<<endl;
	//}
	//delete list;

	//DoublyLinkedList<int>* list = new DoublyLinkedList<int>();

	//list->Pushback(5);
	//list->Pushback(10);
	//list->PushFront(1);
	//list->PushFront(-1);
	//list->Delete(1);

	//list->PopBack();

	//for (int i = 0; i < list->GetLength(); i++) {
	//	cout<<list->At(i)<<endl;
	//}

	//delete list;
	//list = nullptr;

	//Stack<int>* stack = new Stack<int>();
	//stack->Push(-1);
	//stack->Push(100);
	//stack->Push(1);
	//stack->Push(-999);

	//stack->Print();
	//printf("--------------\n");

	//stack->Pop();

	//cout << stack->Top() << endl;

	//delete stack;
	//stack = nullptr;

	//return 0;

	Queue<int>* queue = new Queue<int>();

	queue->Push(1);
	queue->Push(2);
	queue->Push(3);
	queue->Push(4);

	cout << queue->Rear() << endl;
	cout << queue->Front() << endl;
	queue->Pop();
	cout << queue->Rear() << endl;
	queue->Pop();
	queue->Pop();
	queue->Pop();
	cout << queue->Rear() << endl;
	queue->Push(100);
	cout << queue->Rear() << '-' << queue->Front() << endl;

	delete queue;
}