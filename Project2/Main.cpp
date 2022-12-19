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

	DoublyLinkedList<int>* list = new DoublyLinkedList<int>();

	list->Pushback(5);
	list->Pushback(10);
	list->PushFront(1);
	list->PushFront(-1);
	list->Delete(1);

	list->PopBack();

	for (int i = 0; i < list->GetLength(); i++) {
		cout<<list->At(i)<<endl;
	}

	delete list;
	list = nullptr;

	return 0;
}