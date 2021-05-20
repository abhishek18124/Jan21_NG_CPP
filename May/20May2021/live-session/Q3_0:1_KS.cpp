/*

You are packing for a vacation on the sea side and you are going to carry only one bag with capacity 
S (1 <= S <= 1000). You also have N (1<= N <= 1000) items that you might want to take with you to the 
sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. 

For each item you are given its size and its value. You want to maximize the total value of all the 
items you are going to bring. What is this maximum total value?

Input Format
On the first line you are given N and S.
Second line contains N space separated integer where ith integer denotes the size of ith item. 
Third line contains N space seperated integers where ith integer denotes the value of ith item.

*/

#include<iostream>
#include<vector>

using namespace std;


// int KSRecursive(vector<int>& prices, vector<int>& weights, int i, int w) {
// 	// base case
// 	if(i == prices.size() || w == 0) 
// 		return 0;

// 	// recursive case
// 	if(weights[i] > w) {
// 		// exclude the ith item 
// 		return KSRecursive(prices, weights, i+1, w);
// 	} 

// 	int skip = KSRecursive(prices, weights, i+1, w);
// 	int take = prices[i] + KSRecursive(prices, weights, i+1, w-weights[i]);
// 	return max(skip, take);

// }

// int KSTopDown(vector<int>& prices, vector<int>& weights, vector<vector<int>>& memo, int i, int w) {
// 	// base case
// 	if(i == prices.size() || w == 0) 
// 		return 0;

// 	// lookup
// 	if(memo[i][w] != -1) return memo[i][w];

// 	// recursive case
// 	if(weights[i] > w) {
// 		// exclude the ith item 
// 		return memo[i][w]=KSRecursive(prices, weights, i+1, w);
// 	} 

// 	int skip = KSRecursive(prices, weights, i+1, w);
// 	int take = prices[i] + KSRecursive(prices, weights, i+1, w-weights[i]);
// 	return memo[i][w]=max(skip, take);

// }


int main() {

	int n;
	cin >> n;

	int W;
	cin >> W;

	vector<int> weights(n);
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}

	vector<int> prices(n);
	for(int i=0; i<n; i++) {
		cin >> prices[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

	// base case
	for(int i=0; i<=n; i++) {
		dp[i][0] = 0;
	}

	for(int j=0; j<=W; j++) {
		dp[n][j] = 0;
	}

	// recursive
	for(int i=n-1; i>=0; i--) {
		for(int w=1; w<=W; w++) {
			if(weights[i] > w) {
				// I will skip the ith item
				dp[i][w] = dp[i+1][w];
			} else {
				// I have an option to either skip or take the ith item
				dp[i][w] = max(prices[i]+dp[i+1][w-weights[i]], dp[i+1][w]);
			}
		}
	}

	cout << dp[0][W] << endl;
	return 0;
}