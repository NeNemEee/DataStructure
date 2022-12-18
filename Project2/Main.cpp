#include "Framework.h"

int main() {
	//Array* arr = new Array();

	//arr->SetLength(10);
	//arr->Print();
	//arr->Delete();
	//delete arr;

	LinkedList<int>* list = new LinkedList<int>(5);
	list->Add(7);
	list->Add(87);
	list->Add(100);
	list->Delete(100);
	list->AllPrint();
	cout << "---------------------" << endl;
	delete list;

	return 0;
}