/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without 
changing the order of the remaining elements. 

Example 1:
	Input: nums = [10,9,2,5,3,7,101,18]
	Output: 4
	Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
	Input: nums = [0,1,0,3,2,3]
	Output: 4
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int LIS2D(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        // base case
        for(int i=0; i<n; i++) {
            dp[i][n] = 0;
        }
        
        // recursive case
        for(int j=n-1; j>=1; j--) {
            for(int i=0; i<j; i++) {
                int skip = dp[i][j+1];
                int take = 1 + dp[j][j+1];
                if(nums[i] >= nums[j]) {
                    // exclude nums[j]
                    dp[i][j] = skip;
                } else {
                    // you have an option to include or exclude nums[j]
                    dp[i][j] = max(skip, take);
                }
            }
        }    
        return dp[0][1]; 
    }


int LIS1D(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        // base case
        dp[n-1] = 1;
        
        int max_length=1;
        
        // recursive case
        for(int j=n-2; j>=0; j--) {
            int best = 0;
            for(int i=j+1; i<n; i++) {
                if(nums[i] > nums[j])
                    best = max(best, dp[i]);
            }
            dp[j] = 1 + best;
            max_length = max(max_length, dp[j]);
        }
        
        return max_length;
        
    }
    
int lengthOfLIS(vector<int>& nums) {
    // nums.insert(nums.begin(), INT_MIN);
    // return LIS2D(nums);

    return LIS1D(nums);
}

int main() {

	return 0;
}
