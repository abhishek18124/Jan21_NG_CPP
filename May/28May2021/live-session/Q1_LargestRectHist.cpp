/*

Given an array of integers heights representing the histogram's bar height where the 
width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1
	Input: heights = [2,1,5,6,2,3]
	Output: 10

Example 2
	Input: heights = [2,4]
	Output: 4

*/


#include<iostream>
#include<vector>
#include<stack> // Container Adapter which internally uses Deque
#include<deque> // Container

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	vector<int> nsl(n);
	deque<int> stack; // using a deque as a stack

	// for each element in heights, I want to find index of NSL
	for(int i=0; i<n; i++) {
		while(!stack.empty() &&  heights[stack.back()] >= heights[i]) {
			stack.pop_back();
		}

		nsl[i] = stack.empty() ? -1 : stack.back();
		stack.push_back(i);
	}
	
	// there is no guarantee the stack is empty
	stack.clear();

	vector<int> nsr(n);
	for(int i=n-1; i>=0; i--) {
		while(!stack.empty() && heights[stack.back()] >= heights[i]) {
			stack.pop_back();
		}

		nsr[i] = stack.empty() ? n : stack.back();
		stack.push_back(i);
	}

	int maxArea = 0;
	for(int i=0; i<n; i++) {
		maxArea = max(maxArea, (nsr[i]-nsl[i]-1)*heights[i]);
	}

	return maxArea;
}

int main() {


	return 0;
}