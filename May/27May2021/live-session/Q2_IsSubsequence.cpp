/*

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
	Input: s = "abc", t = "ahbgdc"
	Output: true

Example 2:
	Input: s = "axc", t = "ahbgdc"
	Output: false

*/


#include<iostream>
#include<vector>

using namespace std;

bool isSubsequence(string x, string y) {

   int n = x.length();
   int m = y.length();

   vector<vector<bool>> dp(n+1, vector<bool>(m+1));

   // base
   for(int i=0; i<=n; i++) {
   		dp[i][m] = true;
   }

   for(int j=0; j<m; j++) {
   	    dp[n][j] = false;
   }

   // recursive case
   for(int i=n-1; i>=0; i--) {
   		for(int j=0; j<m; j++) {
   			dp[i][j] = x[i] == y[j] ? dp[i+1][j+1] : dp[i+1][j];
   		}
   }

   return dp[0][0];

}

int main() {

	
	return 0;
}