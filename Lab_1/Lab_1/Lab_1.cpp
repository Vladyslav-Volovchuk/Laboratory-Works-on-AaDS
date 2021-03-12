// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* next;
	Node() {
		next = NULL;
	}
	Node(int x, Node* link = NULL) {
		data = x;
		next = link;
	}
};
class List {
private:
	Node* first;
	int count;
public:
	List() { first = NULL; count = 0; }
	~List() {
		Node* temporary = new Node();
		while (first != NULL) {
			temporary = first;
			first = first->next;
			delete temporary;
		}
		delete first;
	}
	void chooseSorting(int item, int oper) {
		switch (oper) {
		case 1:
			ascendingOrd(item);
			break;
		case 2:
			descendingOrd(item);
			break;
		}
	}
	void ascendingOrd(int item) {
		Node* following = first;
		Node* previous = NULL;
		while (following != NULL && following->data <= item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void descendingOrd(int item) {
		Node* following = first;
		Node* previous = NULL;
		while (following != NULL && following->data > item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void addItem(Node* previous, Node* following, int item) {//adding item after defined method of sorting
		if (previous == NULL) {
			first = new Node(item, first);
		}
		else
			previous->next = new Node(item, following);
		count++;
	}
	void printList() {//the operation of printing the whole list sorted
		cout << "\n\nThe content of the List is:\n";
		Node* i = first;
		while (i != NULL) {
			cout << i->data << " ";
			i = i->next;
		}
	}
	bool searchForItem(int item) {
		bool found = false;
		Node* needed = first;
		while (needed->next != NULL && needed->data != item) {
			needed = needed->next;
		}
		if (needed->next == NULL && needed->data != item) { cout << "\nThe item has not been found\n"; return found; }
		else { cout << "\nThe item has been found\n"; found = true; return found; }

	}
	void deleteItem(int item) {
		while(searchForItem(item)){
			Node* needed = first;
			Node* previous = NULL;
			while (needed->data != item && needed->next != NULL) {
				previous = needed;
				needed = needed->next;
			}
			if (needed->data != item && needed->next == NULL) {
				cout << "Needed item has not been found in the list. Try another operation\n\n\n";
			}
			else {
				previous->next = needed->next;
			}
		}
	}
	bool isFull(int size) {
		int result = 1;
		bool res = true;
		Node* firstNode = first;
		while (result < size) {
			firstNode = firstNode->next;
			result++;
		}
		if (result == size) { cout << result << " - List is full!!\n" << endl; return res; }
		else { res = false; return res; }
	}

};
int main()
{
	List A;
	int size;
	
	cout << "Enter the size of a list:\n";
	cin >> size;
	cout << "\n\nChoose the way of sorting your items:\n\n1 - in ascending order;\n2 - in descending order.\nEnter the number of operation: ";
	int oper;
	cin >> oper;
	cout << "\nBegin inputting the items now:\n";	
	for (int i = 0; i < size; i++) {
		int item;
		cin >> item;
		A.chooseSorting(item, oper);//sorting item by the number of operation snd adding to the List;	
	}
	cout << "\n\n" << size << "- List is Full!! Choose the operations among ones mentioned below:\n";
	int operation;
	cout << "1 - Printing the List;\n2 - Searching for an item;\n3 - Deleting the item(all items with the same value will  be removed !!)\n";
	cin >> operation;
	//first version of operations
	switch (operation) {
	case 1:
		A.printList();
		break;
	case 2:
		cout << "\nInput the item that you want to search for:\n";
		int s;
		cin >> s;
		A.searchForItem(s);
		break;
		//case
	}
	
	
	
	
}
