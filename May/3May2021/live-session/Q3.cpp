/*

Given n wines in a row, with integers denoting the cost of each wine respectively. 
Each year you can sale the first or the last wine in the row.However, the price of wines increases 
over time. Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from 
the ith wine will be Y*Pi. Find the maximum profit from all the wines.

*/


#include<iostream>
#include<vector>

using namespace std;

int maxWineProfit(int n, int* wines, int i, int j, int y) {

	// base case
	if(i > j) {
		// no wine bottles left
		return 0;
	}

	int op1 = wines[i]*y + maxWineProfit(n, wines, i+1, j, y+1);
	int op2 = wines[j]*y + maxWineProfit(n, wines, i, j-1, y+1);

	return max(op1, op2);

}

int maxWineProfitTopDown(int n, int* wines, int i, int j, int y, vector<vector<int>>& memo) {

	// base case
	if(i > j) {
		// no wine bottles left
		return 0;
	}

	// lookup
	if(memo[i][j] != -1) {
		return memo[i][j];
	}

	// recursive call
	int op1 = wines[i]*y + maxWineProfitTopDown(n, wines, i+1, j, y+1, memo);
	int op2 = wines[j]*y + maxWineProfitTopDown(n, wines, i, j-1, y+1, memo);

	return memo[i][j]=max(op1, op2);

}

int maxWineProfitBottomUp(int n, int* wines) {

	vector<vector<int>> dp(n, vector<int>(n, 0)); // indirectly handling base case when i>j

	// fill the main diagonal
	for(int i=0; i<n; i++) {
		dp[i][i] = wines[i]*n;
	}

	// fill remaining elements
	int it=1;
	while(it < n) {
		int y = n-it;
		for(int i=0; i<y; i++) {
			int j=it+i;
			int op1 = wines[i]*y + dp[i+1][j];
			int op2 = wines[j]*y + dp[i][j-1];
			dp[i][j] = max(op1, op2);
		}
		it++;
	}

	return dp[0][n-1];
}

int main() {

	int n;
	cin >> n;

	int* wines = new int[n];
	for(int i=0; i<n; i++) {
		cin >> wines[i];
	}

	cout << maxWineProfit(n, wines, 0, n-1, 1) << endl;
	vector<vector<int>> memo(n, vector<int>(n, -1));
	cout << maxWineProfitTopDown(n, wines, 0, n-1, 1, memo) << endl;
	cout << maxWineProfitBottomUp(n, wines) << endl;

	return 0;
}