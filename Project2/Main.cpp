#include "Framework.h"

int main() {
	//Array* arr = new Array();

	//arr->SetLength(10);
	//arr->Print();
	//arr->Delete();
	//delete arr;

	LinkedList<int>* list = new LinkedList<int>();
	
	for (UINT i = 0; i < 10; i++) {
		list->Pushback(i);
	}
	list->Delete(5);
	list->Delete(6);
	list->Insert(5, 5);
	list->Insert(6, 6);
	cout << "---------------------" << endl;
	for (UINT i = 0; i < 10; i++) {
		cout<<list->At(i)<<endl;
	}
	delete list;

	return 0;
}