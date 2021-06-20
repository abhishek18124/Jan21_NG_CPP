/*

Implement a hash table from scratch in C++ to store mapping between food item (string)
and its price (integer).

*/

#include<iostream>

using namespace std;

class Node {
public:
	string key;
	int value;
	Node* next;

	Node(string key, int value) {
		this->key = key;
		this->value = value;
		next = NULL;	
	}

	~Node() {
		if(next != NULL) {
			delete next;
		}
	}
};

class HashTable {
	Node** table;
	int tableSize;
	int currentSize;
	float loadFactorThreshold;

	int hashFunction(string key) {
		int idx = 0;
		int power = 1;
		for(int i=0; i<key.length(); i++) {
			idx = (idx + (key[i] * power) % tableSize) % tableSize;
			power = (power * 27) % tableSize;
		}
		return idx;
	}

	void transfer(Node* head) {
		Node* temp = head;
		while(temp != NULL) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}
		if(head != NULL) delete head;
	}

	void rehash() {
		Node** oldTable = table;
		int oldTableSize = tableSize;

		// expand
		tableSize = tableSize * 2;
		currentSize = 0;
		table = new Node*[tableSize];
		for(int i=0; i<tableSize; i++) {
			table[i] = NULL;
		}

		// transfer nodes from old table 
		for(int i=0; i<oldTableSize; i++) {
			transfer(oldTable[i]);
		}

		delete [] oldTable;
	}

public:
	HashTable(int tableSize, float loadFactorThreshold=0.7) {
		this->tableSize = tableSize;
		this->currentSize = 0;
		table = new Node*[tableSize];
		for(int i=0; i<tableSize; i++) {
			table[i] = NULL;
		}
		this->loadFactorThreshold = loadFactorThreshold;
	}

	void insert(string key, int value) {
		// create node;
		Node* node = new Node(key, value);
		
		// insert at the head of the linked list present at table[idx]
		int idx = hashFunction(key);
		node->next = table[idx];
		table[idx] = node;

		// update the size of the table
		currentSize++;

		float loadFactor = currentSize / (1.0 * tableSize);
		if(loadFactor > loadFactorThreshold) {
			rehash();
		}

	}

	void printLinkedList(Node* head) {
		while(head != NULL) {
			cout << "(" << head->key << ", " << head->value << ")";
			head = head->next;
			if(head != NULL) cout << "->";
		}
		cout << endl;
	}

	void print() {
		for(int i=0; i<tableSize; i++) {
			cout << i << " ";
			printLinkedList(table[i]);
		}
	}

	int* search(string key) {
		int idx = hashFunction(key);
		Node *temp = table[idx];
		while(temp != NULL) {
			if(temp->key == key) {
				return &temp->value;
			}
			temp = temp->next;
		}	
		return NULL;
	}

	int& operator[](string key) {
		int* price = search(key);
		if(price == NULL) {
			int garbage;
			insert(key, garbage);
			price = search(key);
		}
		return *price;
	}

};

int main() {

	HashTable menu(7);

	menu.insert("Burger", 10);
	menu.insert("Pepsi", 20);
	menu.insert("Coke", 40);
	menu.insert("Noodles", 100);
	menu.insert("BurgerPizza", 120);

	menu.print();

	menu["Dosa"] = 60;
	menu["Dosa"] += 20;

	cout << endl;

	menu.print();

	string key = "Burger";
	int* price = menu.search(key);
	price ? cout << key << " has the price = " << *price << endl : cout << key << " is not present in the menu" << endl;

	return 0;
}