/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation. 

Valid operators are +, -, *, and /. Each operand may be an integer or another expression. Note that 
division between two integers should truncate toward zero. 

It is guaranteed that the given RPN expression is always valid. That means the expression would always 
evaluate to a result, and there will not be any division by zero operation.

Example 1:

	Input: tokens = ["2","1","+","3","*"]
	Output: 9

Example 2:
	Input: tokens = ["4","13","5","/","+"]
	Output: 6

Example 3:
	Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
	Output: 22

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> stack;
	string operatorString("+-/*");
	for(string token : tokens) {
		if(operatorString.find(token) == string::npos) {
			stack.push(stoi(token));
		} else {
			int operand2 = stack.top(); stack.pop();
			int operand1 = stack.top(); stack.pop();
			if(token == "+") stack.push(operand1+operand2);
			if(token == "-") stack.push(operand1-operand2);
			if(token == "*") stack.push(operand1*operand2);
			if(token == "/") stack.push(operand1/operand2);
		}
	} 

	return stack.top();
}

int main() {

	return 0;
}
