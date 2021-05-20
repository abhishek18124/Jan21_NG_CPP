/*

Given a linked list, write a function to reverse every k nodes (k>0).

Assumptiom : size of the linked list > 0.

*/

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

};

Node* buildLinkedList() {
	int x; 
	cin >> x; // initially, it cannot be -1

	Node* head = new Node(x);
	Node* curr = head;

	while(x != -1) {
		cin >> x;
		if(x == -1) // do not accept 
			break;

		// insert at end
		Node* n = new Node(x);
		curr->next = n;
		curr = n;
	}

	return head;

}

void printLinkedList(Node* head){
	while(head != NULL) {
		cout << head->data;
		head = head->next;
		if(head) cout << "->";
	}

	cout << endl;
}

Node* kreverse(Node* head, int k) {
	
	// Base Case
	if(head == NULL) {
		return NULL;
	}

	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;

	int cnt = 0;

	while(curr != NULL && cnt != k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}

	head->next = kreverse(curr, k);

	return prev; // new head
}

int main() {

	int k;
	cin >> k;

	Node* head = buildLinkedList();

	// before reverse
	printLinkedList(head);

	// k-reverse
	head = kreverse(head, k);

	// after reverse
	printLinkedList(head);

	return 0;
}