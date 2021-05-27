/*

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some 
(can be none) of the characters without disturbing the remaining characters' relative 
positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.
Example 1:

	Input: s = "rabbbit", t = "rabbit"
	Output: 3
	Explanation:
	As shown below, there are 3 ways you can generate "rabbit" from S.
	rabbbit
	rabbbit
	rabbbit

Example 2:

	Input: s = "babgbag", t = "bag"
	Output: 5
	Explanation:
	As shown below, there are 5 ways you can generate "bag" from S.
	babgbag
	babgbag
	babgbag
	babgbag
	babgbag

*/

#include<iostream>

using namespace std;

unsigned long long numDistinct(string s, string t) {
   int n = s.length();
   int m = t.length();

   vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1));

   // base
   for(int i=0; i<=n; i++) {
   		dp[i][m] = 1;
   }

   for(int j=0; j<m; j++) {
   	    dp[n][j] = 0;
   }

   // recursive case
   for(int i=n-1; i>=0; i--) {
   		for(int j=0; j<m; j++) {
   			dp[i][j] = dp[i+1][j];
   			if(s[i] == t[j]) 
   				dp[i][j] += dp[i+1][j+1];
   		}
   }

   return dp[0][0];
}

int main() {

	
	return 0;
}