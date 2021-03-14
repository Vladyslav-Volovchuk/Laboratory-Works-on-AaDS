// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

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
		cout << "\n\n";
	}
	bool searchForItem(int item) {
		bool found = false;
		Node* needed = first;
		if (needed == NULL) {
			return found;
		}
		while (needed->next != NULL && needed->data != item) {
			needed = needed->next;
		}
		if (needed->next == NULL && needed->data != item) { return found; }
		else { found = true; return found; }

	}
	void deleteItem(int item) {
		while(searchForItem(item)){
			Node* needed = first;
			
			if (needed->data == item && needed != NULL) {
				first = first->next;
				delete needed;
				count--;
			}
			else
			{ 
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
					delete needed;
					count--;
				}
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
	bool isEmpty() {
		bool result = true;
		if (count == 0) {
			cout << "\nList is empty!\n";
			return result;
		}
		else { cout << "\nList is not empty!\n"; result = false; return result; }
	}
	void makeEmpty() {
		count = 0;
		Node* temporary = new Node();
		while (first != NULL) {
			temporary = first;
			first = first->next;
			delete temporary;
		}
		first = new Node(NULL, first);
	}
	int retrieveItem(int item) {
		if (searchForItem(item)) {
			return item;
		}
		else {
			return false;
		}
	}
};
int main()
{
	List A;
	
	while (true) {
		int size;
		cout << "Enter the size of a list:\n";
		cin >> size;
		while (size <= 0) {
			cout << "\nINVALID DATA !! TRY TO INPUT ANOTHER NUMBER:\n";
			cin >> size;
		}		
		cout << "\n\nChoose the way of sorting your items:\n\n1 - in ascending order;\n2 - in descending order.\nEnter the number of operation: ";
		int oper;
		cin >> oper;
		while (oper != 1 && oper != 2) {
			cout << "\nINVALID DATA !! ENTER 1 OR 2 TO CHOOSE THE WAY OF SORTING !\n";
			cin >> oper;
		}
		cout << "\nBegin inputting the items now:\n";
		for (int i = 0; i < size; i++) {
			int item;
			cin >> item;
			A.chooseSorting(item, oper);//sorting item by the number of operation snd adding to the List;	
		}		
		cout << "\n\n" << size << "- List is Full!!";
		while (true) {
			cout << "\nChoose the operations among ones mentioned below:\n";
			int operation;
			cout << "1 - Printing the List;\n2 - Searching for an item;\n3 - Deleting the item(all items with the same value will  be removed !!)\n4- making the List empty\n";
			cin >> operation;
			switch (operation) {
				case 1:
					A.printList();
					break;
				case 2:
					cout << "\nInput the item that you want to search for:\n";
					int s;
					cin >> s;
					if (A.searchForItem(s)) { cout << "\nThe item has been found\n";}
					else { cout << "\nThe item has not been found\n";}
					break;
				case 3:
					cout << "\nInput the item that you want to delete with all repetitions:\n";
					int del_num;
					cin >> del_num;
					A.deleteItem(del_num);
					A.printList();
					break;
				case 4:
					A.makeEmpty();
					cout << "\nThe List has been got rid of all items\n";
					break;
			}
		}
		
	}
	
}
