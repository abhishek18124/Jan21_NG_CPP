/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock. Return the maximum profit you can achieve from this transaction.

 If you cannot achieve any profit, return 0.

 Example 1:

	Input: prices = [7,1,5,3,6,4]
	Output: 5

Example 2:

	Input: prices = [7,6,4,3,1]
	Output: 0

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int minPrice = INT_MAX;
	for(int i=0; i<prices.size(); i++) {
		if(prices[i] < minPrice) {
			minPrice = prices[i]; // buy-day
		} else {
			profit = max(profit, prices[i]-minPrice);
		}
	}
	return profit;
}

int main() {

	vector<int> prices{7,6,4,3,1};
	cout << maxProfit(prices) << endl;
	return 0;
}
