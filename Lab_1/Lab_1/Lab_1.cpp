// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node() {
		next = NULL;
	}
	Node(T x, Node* link = NULL) {
		data = x;
		next = link;
	}
};
template<typename T>
class List {
private:
	Node<T>* first;
	int count;
public:
	List() { first = NULL; count = 0; }
	~List() {
		Node<T>* temporary = new Node<T>();
		while (first != NULL) {
			temporary = first;
			first = first->next;
			delete temporary;
		}
		delete first;
	}
	void sortingThenAdding(T item, int oper) {
		switch (oper) {
		case 1:
			ascendingOrd(item);
			break;
		case 2:
			descendingOrd(item);
			break;
		}
	}
	void ascendingOrd(T item) {
		Node<T>* following = first;
		Node<T>* previous = NULL;
		while (following != NULL && following->data <= item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void descendingOrd(T item) {
		Node<T>* following = first;
		Node<T>* previous = NULL;
		while (following != NULL && following->data > item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void addItem(Node<T>* previous, Node<T>* following, T item) {//adding item after defined method of sorting
		if (previous == NULL) {
			first = new Node<T>(item, first);
		}
		else
			previous->next = new Node<T>(item, following);
		count++;
	}

	void printList(List* A) {//the operation of printing the whole list sorted
		cout << "\n\nThe content of the List is:\n";
		Node<T>* i = A->first;
		while (i != NULL) {
			cout << i->data << " ";
			i = i->next;
		}
		cout << "\n\n";
	}

	bool searchForItem(T item) {
		bool found = false;
		Node<T>* needed = first;
		if (needed == NULL) {
			return found;
		}
		while (needed->next != NULL && needed->data != item) {
			needed = needed->next;
		}
		if (needed->next == NULL && needed->data != item) { return found; }
		else { found = true; return found; }

	}

	void deleteItem(T item) {
		while(searchForItem(item)){
			Node<T>* needed = first;
			
			if (needed->data == item && needed != NULL) {
				first = first->next;
				delete needed;
				count--;
			}
			else
			{ 
				Node<T>* previous = NULL;
				while (needed->data != item && needed->next != NULL) {
					previous = needed;
					needed = needed->next;
				}
				if (needed->data != item && needed->next == NULL) {
					cout << "Needed item has not been found in the list. Try another operation\n\n\n";
				}
				else {
					previous->next = needed->next;
					delete needed;
					count--;
				}
			}
			
		}
	}

	bool isFull(int size) {
		bool res = true;
		if (count == size) {  return res; }//result
		else { res = false; return res; }
	}

	bool isEmpty() {
		bool result = true;
		if (count == 0) {
			return result;		
		}
		else {result = false; return result; }
	}

	void makeEmpty() {
		count = 0;
		Node<T>* temporary = new Node<T>();
		while (first != NULL) {
			temporary = first;
			first = first->next;
			delete temporary;
		}
	}

	int retrieveItem(T item) {
		if (searchForItem(item)) {
			return item;
		}
		else {
			cout << "\nNothing to retrieve\n";
		}
	}
	
	void reverse_copy(List* A) {
		List<T> B = List<T>();
		int count_2 = A->count;

		for (int k = 1; k <= count_2; k++) {
			Node<T>* head = A->first;
			if (k == 1) {
				B.addItem(NULL, head, head->data);
			}
			else{
				for (int j = 1; j < k; j++) {
					head = head->next;
				}
				B.addItem(NULL, head, head->data);
			}
		}
		printList(&B);
	}
};


int main()
{
	List<int> A;
	List<string> B;

	while (true) {
		//размер списка
		int size;
		cout << "Enter the size of a list:\n";
		cin >> size;
		while (size <= 0) {
			cout << "\nINVALID DATA !!\nYOU WILL NOT BE ABLE TO INPUT NUMBERS !!\nTRY TO INPUT ANOTHER NUMBER:\n";
			cin >> size;
		}	

		//выбор сортировки
		cout << "\n\nChoose the way of sorting your items:\n\n1 - in ascending order;\n2 - in descending order.\nEnter the number of operation: ";
		int oper;
		cin >> oper;
		while (oper != 1 && oper != 2) {
			cout << "\nINVALID DATA !! ENTER 1 OR 2 TO CHOOSE THE WAY OF SORTING !\n";
			cin >> oper;
		}

		//вставка элементов
		cout << "\nBegin inputting the items now:\n";
		for (int i = 0; i < size; i++) {
			int item;
			//string item;
			cin >> item;
			A.sortingThenAdding(item, oper);
			//B.sortingThenAdding(item, oper);
			
		}
		cout << "\n\n" << size << "- List is Full!!";

		//operations with the List

		int add, del;
		//string add, del;
		while (true) {
			cout << "\nChoose the operations among ones mentioned below:\n";
			int operation;
			cout << "1 - Printing the List;\n2 - Searching for an item;\n3 - Deleting the item(all items with the same value will  be removed !!)";
			cout << "\n4 - making the List empty\n5 - adding a new item to the list\n6 - Print the List in reverse order\n";
			cin >> operation;
			switch(operation) {
			case 1://printing
				A.printList(&A);
				//B.printList(&B);
				break;
			case 2://searching
				if (A.isEmpty()) {//B
					cout << "\nList is empty!\n";
					break;
				}	
				else {
					cout << "\nInput the item that you want to search for:\n";
					int s;
					//string s;
					cin >> s;
						if (A.searchForItem(s)) {//B
							cout << "\nThe item has been found\n"; 
						}
						else { cout << "\nThe item has not been found\n"; }
				}	
				break;
			case 3://deleting
				cout << "\nInput the item that you want to delete with all repetitions:\n";
				cin >> del;
				A.deleteItem(del);
				//B.deleteItem(del);
				A.printList(&A);
				//B.printList(&B);
				break;
			case 4://making empty
				A.makeEmpty();
				//B.makeEmpty();
				cout << "\nThe List has been got rid of all items\n";
				break;
			case 5://adding item
				if (A.isFull(size) == true) {//B
					cout << size << " - List is full!!\n" << endl;
				}			
				else {
					cout << "\nInput the item that you want to add to the List:\n";
					cin >> add;
					A.sortingThenAdding(add, oper);//B
				}
			case 6://reversing
				A.reverse_copy(&A);
				//B.reverse_copy(&B);
			}
		}

	}
}
