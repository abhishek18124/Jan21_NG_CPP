/*

You are keeping score for a baseball game with strange rules. 
The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. 
You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record 
and is one of the following:

An integer x - Record a new score of x.

"+" - Record a new score that is the sum of the previous two scores. 
      It is guaranteed there will always be two previous scores.

"D" - Record a new score that is double the previous score. 
      It is guaranteed there will always be a previous score.

"C" - Invalidate the previous score, removing it from the record. 
      It is guaranteed there will always be a previous score.

Return the sum of all the scores on the record.

Example 1 

Input: ops = ["5","2","C","D","+"]
Output: 30

Example 2

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27

*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int calPoints(vector<string>& ops) {

	stack<int> stack;
	int sum=0;
	for(string op : ops) {
		if(op == "+") {
			int x = stack.top(); stack.pop();
			int y = stack.top();
			stack.push(x);
			stack.push(x+y);
			sum += stack.top();
		} else if(op == "D") {
			stack.push(2*stack.top());
			sum += stack.top();
		} else if(op == "C") {
			sum -= stack.top();
			stack.pop();
		} else {
			stack.push(stoi(op));
			sum += stack.top();
		}
	}

	// int sum=0;
	// while(!stack.empty()) {
	// 	sum += stack.top();
	// 	stack.pop();
	// }

	return sum;
}

int main() {

	
	return 0;
}
