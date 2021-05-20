/*

The stock span problem is a financial problem where we have a series of N daily price quotes for a stock 
and we need to calculate span of stock’s price for all N days. You are given an array of length N, where 
ith element of array denotes the price of a stock on ith. Find the span of stock's price on ith day, for 
every 1<=i<=N. A span of a stock's price on a given day, i, is the maximum number of consecutive days 
before the (i+1)th day, for which stock's price on these days is less than or equal to that on the ith day.

Example 1:

Input : 30 35 40 38 35
Output: 1  2  3  1  1  END

Example 2:

Input : 8 7 4 3 6 9 1
Output: 1 1 1 1 3 6 1 END


*/


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> prices(n);
	for(int i=0; i<n; i++) {
		cin >> prices[i];
	}

	vector<int> out(n);

	stack<int> stack;
	for(int i=0; i<prices.size(); i++) {
		while(!stack.empty() && prices[stack.top()] <= prices[i]) {
			stack.pop();
		}

		int j;

		if(stack.empty()) {
			// you could not find a day on the left of the ith day
			// where price became greater
			j = -1;
		} else {
			// you found a day on which the price become greater
			// than the price on the ith day.
			j = stack.top();
		}

		out[i] = i - j;

		// out[i] = stack.empty()? i+1 : i-stack.top();
		
		stack.push(i);	
	}

	for(int i=0; i<out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << "END" << endl;

	return 0;
}