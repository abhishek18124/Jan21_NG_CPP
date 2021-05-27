/*

Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the 
given set with sum equal to given sum.

Input Format
1st Line: n sum 
2nd Line: a1 a2……an (Array Values)

*/

#include<iostream>

using namespace std;

bool subsetSum(vector<int> v, int S) {
	int n = v.size();
	vector<vector<int>> dp(n+1, vector<int>(S+1, -1));

	// base case
	for(int i=0; i<=n; i++) {
		dp[i][0] = true;
	}

	for(int s=1; s<=S; s++) {
		dp[n][s] = false;
	}

	// recursive case
	for(int i=n-1; i>=0; i--) {
		for(int s=1; s<=S; s++) {
			if(v[i] <= s) {
				dp[i][s] = dp[i+1][s] || dp[i+1][s-v[i]];
			} else {
				dp[i][s] = dp[i+1][s];
			}
		}
	}

	return dp[0][S];
}

int main() {

	
	return 0;
}