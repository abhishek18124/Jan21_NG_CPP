/*

Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...

*/

#include<iostream>
#include<stack>

using namespace std;

char evalOr(string inner_expr) {
	for(int i=0; i<inner_expr.length(); i++) {
		char ch = inner_expr[i];
		if(ch == 't') 
			return 't';
	}
	return 'f';
}


char evalAnd(string inner_expr) {
	for(int i=0; i<inner_expr.length(); i++) {
		char ch = inner_expr[i];
		if(ch == 'f') 
			return 'f';
	}
	return 't';
}

char evalNot(string inner_expr) {

	char ch = inner_expr[0];
	if(ch == 't')
		return 'f';
	return 't';
}

void evalInnerBoolExpr(stack<char> &stack){

	string inner_expr = "";

	while(!stack.empty()) {
		char ch = stack.top();
		stack.pop();

		if(ch == '(') {
			// I am sure inner express has been built
			char op = stack.top();
			stack.pop();

			switch(op) {
				case '|' : stack.push(evalOr( inner_expr)); break;
				case '&' : stack.push(evalAnd(inner_expr)); break;
				case '!' : stack.push(evalNot(inner_expr)); break;
			}

			break;

		} else { // 't' or 'f'
			// build inner expression
			inner_expr += ch;
		}
	}
}

bool evalBoolExpr(string expr) {

	stack<char> stack;
	for(int i=0; i<expr.length(); i++) {
		char ch = expr[i];
		if(ch == ')') {
			// build & evaluate the inner expr
			evalInnerBoolExpr(stack);
		} else if(ch == ',') {
			// ignore, do nothing
		} else { // ch='&, |, !, t, f, ('
			stack.push(ch);
		}
	}

	return stack.top() == 't';

}

int main() {

	string expr;

	while(getline(cin, expr)) {
		cout << expr << " : " << evalBoolExpr(expr) << endl;
	}
	
	return 0;
}
