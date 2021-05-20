/*

Given an array of integers, find the nearest/closest greater value on right of every element. 
If an element has no greater value on the right side, print -1.

Example 1 :

	Input:  [ 8, 2,  7, 4, 3,  6]
	Output: [-1, 7, -1, 6, 6, -1]

Example 2 : 

	Input:  [4, 6, 3, 2, 5,  9]
	Output: [6, 9, 5, 5, 9, -1]

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	vector<int> nums{4, 6, 3, 2, 5,  9};
	vector<int> out(nums.size());

	stack<int> stack;
	for(int i=nums.size()-1; i>=0; i--) {
		while(!stack.empty() && nums[stack.top()] <= nums[i]) {
			stack.pop();
		}

		out[i] = stack.empty() ? -1 : stack.top();
		stack.push(i);
	}

	for(int i=0; i<out.size(); i++) {
		if(out[i] != -1) 
			out[i] = nums[out[i]];
		cout << out[i] << " ";
	}

	cout << endl;
	return 0;
}

