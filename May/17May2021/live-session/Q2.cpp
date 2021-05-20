/*

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return 
the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the 
array, which means you could search circularly to find its next greater number. If it doesn't exist, 
return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]

Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

*/

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

	vector<int> out(nums.size());
	deque<int> stack;

	// 1st pass
	for(int i=nums.size()-1; i>=0; i--) {
		while(!stack.empty() && nums[stack.back()] <= nums[i])
			stack.pop_back();

		out[i] = stack.empty() ? -1 : stack.back();

		stack.push_back(i);
	}

	int j = stack.front();

	// 2nd pass
	for(int i=nums.size()-1; i>j; i--) {
		while(out[i] == -1 && !stack.empty() && nums[stack.back()] <= nums[i])
			stack.pop_back();

		if(out[i] == -1) {
			out[i] = stack.empty() ? -1 : stack.back();
		}

		// no push

	}

	for(int i=0; i<out.size(); i++)
		if(out[i] != -1)
			out[i] = nums[out[i]];

	return out;

}

int main() {

	
	return 0;
}