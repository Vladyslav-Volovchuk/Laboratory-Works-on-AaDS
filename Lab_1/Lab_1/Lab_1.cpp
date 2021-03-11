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
		while (following->next != NULL && following->data <= item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void descendingOrd(int item) {
		Node* following = first;
		Node* previous = NULL;
		while (following->next != NULL && following->data > item) {
			previous = following;
			following = following->next;
		}
		addItem(previous, following, item);//method of adding item to the list
	}
	void addItem(Node* previous, Node* following, int item) {//adding item after defined method of sorting
		if (previous = NULL) {
			first = new Node(item, first);
		}
		else
			previous = new Node(item, following);
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
};
int main()
{
	int size;
	cout << "Enter the size of a list:\n";
	cin >> size;
	cout << "\n\nChoose the way of sorting your items:\n\n1 - in ascending order;\n2 - in descending order.\nEnter the number of operation: ";
	for (int i = 0; i < size; i++) {
		//adding item;
		//sorting item by the number of operation;
	}
	cout << "\n\n" << size << "- List is Full!! Choose the operations among ones mentioned below:\n";
	cout << "1 - Printing the List;\n2 - Searching for an item;\n3 - Deleting the item";//first version
}
