/*

In combinatorial mathematics, a derangement is a permutation of the elements of a set, 
such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, 
you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 10^9 + 7.

Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

N > 0

*/

#include<iostream>

using namespace std;

int countDerangements(int n) {

	// base cases
	if(n == 1) return 0;
	if(n == 2) return 1;

	// recursive case
	return (n-1) * (countDerangements(n-1) + countDerangements(n-2));

}

int countDerangementsTopDown(int n, int* memo) {

	// base cases
	if(n == 1) return 0;
	if(n == 2) return 1;

	// lookup
	if(memo[n] != -1)
		return memo[n];

	// recursive case
	return memo[n]= (n-1)*(countDerangementsTopDown(n-1, memo) + 
		                  countDerangementsTopDown(n-2, memo));

}


int countDerangementsBottomUp(int n) {

	if(n == 1) return 0;
	if(n == 2) return 1;

	// 1....n
	int* dp = new int[n+1];

	// base cases
	dp[1]=0;
	dp[2]=1;

	// recursive case
	for(int i=3; i<=n; i++)
		dp[i] = (i-1) * (dp[i-1] + dp[i-2]);

	return dp[n];

}


int countDerangementsBottomUpSpaceOptimised(int n) {

	if(n == 1) return 0;
	if(n == 2) return 1;

	
	// base cases
	int first=0;
	int second=1;

	// recursive case
	for(int i=3; i<=n; i++) {
		int third = (i-1) * (second + first);
		first = second;
		second = third;
	}

	return second;

}


int main() {


	int n;
	cin >> n;

	cout << countDerangements(n) << endl;

	int* memo = new int[n+1];
	for(int i=0; i<=n; i++)
		memo[i]=-1;

	cout << countDerangementsTopDown(n, memo) << endl;

	cout << countDerangementsBottomUp(n) << endl;

	cout << countDerangementsBottomUpSpaceOptimised(n) << endl;

	return 0;
}
