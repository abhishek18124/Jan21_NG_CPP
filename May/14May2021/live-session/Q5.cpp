/*

Design a stack class that supports the following operations

1. Push
2. Pop
3. Top
4. GetMin
5. GetMax

*/

#include<iostream>
#include<vector>

using namespace std;

class MinMaxStack {

	vector<int> stack;
	vector<int> minStack;
	vector<int> maxStack;

public:
	void push(int data) {
		int current_min = data;
		int current_max = data;

		if(!empty()) current_min = min(current_min, minStack[minStack.size()-1]);
		if(!empty()) current_max = max(current_max, maxStack[maxStack.size()-1]);

		stack.push_back(data);
		minStack.push_back(current_min);
		maxStack.push_back(current_max);
	}

	void pop() {
		stack.pop_back();
		minStack.pop_back();
		maxStack.pop_back();
	}

	int top() {
		return stack[stack.size()-1];
	}

	int getMin() {
		return minStack[minStack.size()-1];
	}

	int getMax() {
		return maxStack[maxStack.size()-1];
	}

	bool empty() {
		return stack.size()==0;
	}

};

int main() {

	MinMaxStack minMaxStack;

	minMaxStack.push(1);
	minMaxStack.push(5);
	minMaxStack.push(3);
	minMaxStack.push(8);

	cout << minMaxStack.getMax();
	cout << minMaxStack.getMin();
	minMaxStack.pop();
	cout << minMaxStack.getMax();

	minMaxStack.pop();
	minMaxStack.pop();
	cout << minMaxStack.top();
	cout << minMaxStack.getMax();

	return 0;
}