

/*

Given two intersecting linked lists, write a function to find its point of intersection. 
If the lists do not intersect , return NULL.

Note: It is assured that the two lists intersect

Approach 2 : ~(N+M) Steps

*/

#include<iostream>
#include<unordered_map>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}

};

void printLinkedList(Node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->next;
		if(head) cout << "->";
	}
	cout << endl;
}

Node* buildList(unordered_map<int, Node*> &map) {
	int x;
	cin >> x; // initially, x cannot be -1

	Node* head = new Node(x);
	map[x] = head;
	Node* curr = head;

	while(x != -1) {
		cin >> x;
		if(x == -1)
			break;
		Node* n = new Node(x);
		map[x] = n;
		
		curr->next = n;
		curr = n;
	}

	return head;
}

// Approach 2

int lengthOfLinkedList(Node* head) {
	int cnt=0;
	while(head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

Node* intersectionOfTwoLinkedLists(Node* head1, Node* head2) {

	int len1 = lengthOfLinkedList(head1);
	int len2 = lengthOfLinkedList(head2);

	Node* p = head1;
	Node* q = head2;

	if(len1 > len2) {
		int diff = len1 - len2;
		// move p by diff steps
		while(diff--){
			p = p->next;
		}
	} else {
		int diff = len2 - len1;
		// move q by diff steps
		while(diff--){
			q = q->next;
		}
	}

	// while(p != q) {
	// 	p = p->next;
	// 	q = q->next;
	// }

	// return p;
	
	while(p != NULL && q!= NULL) {
		if(p == q)
			return p;
		p = p->next;
		q = q->next;
	}

	return NULL;
}


int main() {

	unordered_map<int, Node*> map;
	Node* head1 = buildList(map);

	int x;
	cin >> x;

	Node* head2 = NULL;
	if(map.find(x) != map.end()) {
		head2 = map[x];

		cout << "Linked List 1 : ";
		printLinkedList(head1);
		
		cout << "Linked List 2 : ";
		printLinkedList(head2);

    	cout << "Intersection at node with data = " << head2->data << endl;

		return 0;
	}

	head2 = new Node(x);
	Node* curr  = head2;

	while(x != -1){
		cin >> x;
		if(x == -1)
			break;

		if(map.find(x) != map.end()) {
			curr->next = map[x];
			break;
		}

		Node* n = new Node(x);
		curr->next = n;
		curr = n;
	}

	cout << "Linked List 1 : ";
	printLinkedList(head1);
	
	cout << "Linked List 2 : ";
	printLinkedList(head2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(head1, head2);
    intersectionPoint? cout << "Intersection at node with data = " << intersectionPoint->data << endl :
                       cout << "Intersection not found" << endl ;

	return 0;
}