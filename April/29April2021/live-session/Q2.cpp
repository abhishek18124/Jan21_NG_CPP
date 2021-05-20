/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
have security systems connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Examples

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 
*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(int* nums, int n, int i) {

	if(i >= n)
		// no houses to consider
		return 0;

	// I am standing at the ith house and I have to make a decision

	// rob the ith house
	int x = maxProfit(nums, n, i+2);

	// skip the ith house
	int y = maxProfit(nums, n, i+1);

	return max(nums[i]+x, y);

}

int maxProfitTopDown(int* nums, int n, int i, vector<int>& memo) {

	// base case
	if(i >= n)
		return 0;

	// lookup
	if(memo[i] != -1)
		return memo[i];

	// recursive case
	return memo[i]=max(nums[i]+maxProfitTopDown(nums, n, i+2, memo), 
		               maxProfitTopDown(nums, n, i+1, memo));

}

int maxProfitBottomUp(int* nums, int n) {

	vector<int> dp(n+1);
	
	// base case
	dp[n]=0; // no house left to rob
	dp[n-1]=nums[n-1]; // only one house left i.e. the last house so rob it to maximize profit

	// recursive
	for(int i=n-2; i>=0; i--)
		dp[i] = max(nums[i]+dp[i+2], dp[i+1]);

	return dp[0];

}

int maxProfitBottomUpSpaceOptimised(int* nums, int n) {

	// base case
	int first=0;
	int second=nums[n-1];

	// recursive
	for(int i=n-2; i>=0; i--) {
		int third = max(nums[i]+first, second);
		first = second;
		second = third;
	}

	return second;

}


int main() {

	int n;
	cin >> n;

	int* nums = new int[n];
	for(int i=0; i<n; i++)
		cin >> nums[i];

	cout << maxProfit(nums, n, 0) << endl;

	vector<int> memo(n, -1);
	cout << maxProfitTopDown(nums, n, 0, memo) << endl;

	cout << maxProfitBottomUp(nums, n) << endl;

	cout << maxProfitBottomUpSpaceOptimised(nums, n) << endl;

	return 0;
}
