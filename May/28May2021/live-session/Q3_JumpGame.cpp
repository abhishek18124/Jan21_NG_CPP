/*

Given an array of non-negative integers nums, you are initially positioned at the first 
index of the array.

Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:

	Input: nums = [2,3,1,1,4]
	Output: true

Example 2:

	Input: nums = [3,2,1,0,4]
	Output: false

*/

#include<iostream>
#include<unordered_map>

using namespace std;

bool canJumpRecursive(vector<int>& A, int i) {
	if(i == A.size()-1) {
		return true;
	}

	bool canJump = false;
	for(int j=1; j<=A[i]; j++) {
		if(i+j < A.size()) {
			canJump = canJump || canJumpRecursive(A, i+j);
		}
	}

	return canJump;
}

bool canJumpTopDown(vector<int>& A, int i, unordered_map<int, bool>& memo) {
	// Base Case
	if(i == A.size()-1) {
		return true;
	}

	// Lookup
	if(memo.find(i) != memo.end()) 
		return memo[i];

	// Recursive Call
	bool canJump = false;
	for(int j=1; j<=A[i]; j++) {
		if(i+j < A.size()) {
			canJump = canJump || canJumpTopDown(A, i+j, memo);
		}
	}

	return memo[i]=canJump;
}

bool canJumpBottomUp(vector<int>& A) {
	int n = A.size();
	vector<bool> dp(n, false);

	// base case
	dp[n-1] = true;

	// recursive case
	for(int i=n-2; i>=0; i--) {
		for(int j=1; j<=A[i]; j++) {
			if(i+j < n) {
				dp[i] = dp[i] || dp[i+j];
			}
			if(dp[i]) break;
		}
	}

	return dp[0];
}

bool canJump(vector<int>& nums) {
	unordered_map<int, bool> memo;
	return canJumpTopDown(nums, 0, memo);
	// return canJumpRecursive(nums, 0);
}

int main() {


	return 0;
}