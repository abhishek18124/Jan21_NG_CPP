/*

Given an array of non-negative integers nums, you are initially positioned at the first 
index of the array.

Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:

	Input: nums = [2,3,1,1,4]
	Output: 2

Example 2:

	Input: nums = [2,3,0,1,4]
	Output: 2

*/

#include<iostream>

using namespace std;

int jumpRecursive(vector<int>& A, int i) {

	// base case
	if(i == A.size()-1) {
		return 0;
	}

	// recursive case
	int minJumps = 10007;
	for(int j=1; j<=A[i]; j++) {
		if(i+j < A.size())
			minJumps = min(minJumps, 1+jumpRecursive(A, i+j));
	}

	return minJumps;
}

int jumpBottomUp(vector<int>& A) {

	int n = A.size();
	vector<int> dp(n, 10007);

	// base case
	dp[n-1] = 0;

	// recursive case
	for(int i=n-2; i>=0; i--) {
		for(int j=1; j<=A[i]; j++) {
			if(i+j < n) {
				dp[i] = min(dp[i], 1+dp[i+j]);
			}
		}
	}

	return dp[0];
}

int jump(vector<int>& nums) {

}

int main() {


	return 0;
}