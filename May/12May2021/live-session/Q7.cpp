/*

Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

*/

#include<iostream>

using namespace std;

ListNode* swapPairsRecursive(ListNode* head) {

	if(head == NULL && head->next == NULL)
		return head;

	//extract nodes to be swapped
	ListNode* firstNode = head;
	ListNode* secondNode = head->next;

	// swapping
	firstNode->next = swapPairsRecursive(secondNode->next);
	secondNode->next = firstNode;

	// return updated head
	return secondNode;
}

ListNode* swapPairsIterative(ListNode* head) {

	if(head == NULL || head->next == NULL)
		return head;


	ListNode* temp = head;

	//extract nodes to be swapped
	ListNode* firstNode  = temp;
	ListNode* secondNode = temp->next;

	// swapping
	firstNode->next = secondNode->next;
	secondNode->next = firstNode;

	// update temp
	temp = firstNode->next;
	head = secondNode;
	ListNode* prevNode = firstNode;

	while(temp != NULL && temp->next != NULL) {
		//extract nodes to be swapped
		firstNode  = temp;
		secondNode = temp->next;

		// swapping
		firstNode->next = secondNode->next;
		secondNode->next = firstNode;
		prevNode->next = secondNode;

		// update temp
		temp = firstNode->next;
		prevNode = firstNode;
	}

	return head;

}




int main() {

	
	return 0;
}