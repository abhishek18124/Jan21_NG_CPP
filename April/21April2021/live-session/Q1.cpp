/*

Given a linked list having two pointers in each node. 
The first one points to the next node of the list, however, 
the other pointer is random and can point to any node of the list. 

Write a program that clones the given list

Note: size of the linked list is greater than 0.

*/

#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data) {
		this->data = data;
		this->next = this->prev = NULL;
	}

};


void printDoublyLinkedList(Node* head) {
	while(head != NULL) {

		cout << "[";
		head->prev && head->next  ? cout << head->prev->data << " " 
		                                   << head->data << " " 
		                                   << head->next->data :

		head->prev && !head->next ? cout << head->prev->data << " "
									       << head->data << " "
									       << "NULL" :

		!head->prev && head->next ? cout << "NULL " 
									       << head->data << " "
									       << head->next->data :

					   				  cout << "NULL " 
						   		           << head->data << " "
						   		           << "NULL";

		cout << "]";

		head = head->next;
		if(head) cout << "->";
	}

	cout << endl;
}

void printSinglyLinkedList(Node* head) {
	while(head != NULL) {
		cout << "[" << head->data << "]";
		head = head->next;
		if(head) cout << "->";
	}

	cout << endl;
}

Node* cloneLinkedList(Node* head) {

	// 1. insert a copy of the ith node between the ith & (i+1)th node
	Node* curr = head;
	while(curr != NULL) {
		Node* save = curr->next;

		// inserted n betwen curr & save
		Node* n = new Node(curr->data);
		curr->next = n;
		n->next = save;
		curr = save;
	}

	// printDoublyLinkedList(head);
	// printSinglyLinkedList(head);

	// 2. set the prev pointer for every newly created node
	curr = head;
	while(curr != NULL) {
		// curr != NULL 
		if(curr->next != NULL)
			curr->next->prev = curr->prev ? curr->prev->next : NULL;
		curr = curr->next ? curr->next->next : NULL;
	}

	// printDoublyLinkedList(head);

	// 3. adjust the next pointer for every node such that the two lists are separated
	Node* cloneHead = head->next;

	curr = head;
	Node* copy = cloneHead;

	while(curr != NULL && copy != NULL) {
		curr->next = curr->next ? curr->next->next : NULL;
		copy->next = copy->next ? copy->next->next : NULL;

		curr = curr->next;
		copy = copy->next;
	}

	return cloneHead;

}

int main() {

	// setup forward links
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);

	// setup the backward links
	head->prev = head->next->next; // 3<-1
	head->next->prev = head->next->next->next; // 4<-2
	head->next->next->prev = head; // 1<-3
	head->next->next->next->prev = head->next; // 2<-4

	printDoublyLinkedList(head);

	Node* cloneHead = cloneLinkedList(head);

	printDoublyLinkedList(cloneHead);

	Node* p = head;
	Node* q = cloneHead;

	while(p != q) {
		cout << "X" << " ";
		p = p->next;
		q = q->next;
	}

	return 0;
}