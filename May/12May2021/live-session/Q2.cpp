/*

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function 
of the form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array 
in a sorted order.

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
*/

#include<iostream>
#include<vector>

using namespace std;

int transform(int x, int a, int b, int c) {
	return a*x*x + b*x + c;
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
	int i=0;
	int j=nums.size()-1;

	vector<int> out(nums.size());

	if(a >= 0) {
		// +ve parabola, fill from right to left
		int k=out.size()-1;
		while(i<=j) {
			if(transform(nums[i], a, b, c) > transform(nums[j], a, b, c)) {
				out[k] = transform(nums[i], a, b, c);
				i++;
			} else {
				out[k] = transform(nums[j], a, b, c);
				j--;
			}
			k--;
		}

	} else {
		// -ve parabola, fill from left to right
		int k=0;
		while(i<=j) {
			if(transform(nums[i], a, b, c) < transform(nums[j], a, b, c)) {
				out[k] = transform(nums[i], a, b, c);
				i++;
			} else {
				out[k]  = transform(nums[j], a, b, c);
				j--;
			}
			k++;
		}
	}

	return out;
}

int main() {
	
	vector<int> nums{-4,-2,2,4};
	int a=0;
	int b=3;
	int c=5;

	vector<int> out = sortTransformedArray(nums, a, b, c);
	for(int x : out) cout << x << " ";
	cout << endl;
	return 0;
}