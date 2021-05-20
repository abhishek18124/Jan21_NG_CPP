/*

Given an array of integers, find the closest/nearest greater value on left of every element. 
If an element has no greater value on the left side, print -1.

Example 1 :

	Input:  [ 8, 2, 7, 4, 3, 6]
	Output: [-1, 8, 8, 7, 4, 7]

Example 2 : 
	Input:  [ 4,  6, 3, 2, 5,  9]
	Output: [-1, -1, 6, 3, 6, -1]

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	// With values

	// vector<int> nums{8, 2, 7, 4, 3, 6};
	// vector<int> out(nums.size());

	// stack<int> stack;
	// for(int i=0; i<nums.size(); i++) {
	// 	while(!stack.empty() && stack.top() <= nums[i])
	// 		stack.pop();

	// 	out[i] = stack.empty() ? -1 : stack.top();

	// 	stack.push(nums[i]);
	// }

	// for(int i=0; i<out.size(); i++) 
	// 	cout << out[i] << " ";

	// cout << endl;

	// With indices

	vector<int> nums{8, 2, 7, 4, 3, 6};
	vector<int> out(nums.size());

	stack<int> stack;
	for(int i=0; i<nums.size(); i++) {
		while(!stack.empty() && nums[stack.top()] <= nums[i])
			stack.pop();

		out[i] = stack.empty() ? -1 : stack.top();

		stack.push(i);
	}

	for(int i=0; i<out.size(); i++) 
		if(out[i] != -1) cout << nums[out[i]] << " ";
		else cout << -1 << " ";

	cout << endl;


	return 0;
}