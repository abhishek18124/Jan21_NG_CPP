/*

Given an integer array nums, return the increasing subsequence maximum sum.

Example 1: 
	Input : {1, 101, 2, 3, 100, 4, 5}
	Output: 106 (1 + 2 + 3 + 100)

Example 2:
	Input : {3, 4, 5, 10} 
	Output: 22 (3 + 4 + 5 + 10)

Example 3:
	Input : {10, 5, 4, 3}
	Output: 10

*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int IS_Max2D(vector<int>& nums) {
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
                int take = nums[j] + dp[j][j+1]; // only change from LIS, nums[j] instead of 1
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

    
int IS_Max(vector<int>& nums) {
    nums.insert(nums.begin(), INT_MIN);
    return IS_Max2D(nums);

    // return IS_Max1D(nums);
}

int main() {

	vector<int> nums{10, 5, 4, 3};
	cout << IS_Max(nums);
	return 0;
}

