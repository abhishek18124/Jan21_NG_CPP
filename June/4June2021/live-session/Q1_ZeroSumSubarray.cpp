/*

Given an array of positive and negative numbers, find if there is a subarray 
(of size at-least one) with 0 sum.

Input: {4, 2, -3, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 2 to 2.

Input: {-3, 2, 3, 1, 6}
Output: false

*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool zeroSumSubarray(vector<int>& v) {
	int prefixSum = 0;
	unordered_set<int> set;
	for(int i=0; i<v.size(); i++) {
		prefixSum += v[i];
		if(prefixSum == 0 || set.find(prefixSum) != set.end()) {
			return true;
		}
		set.insert(prefixSum);
	}
	return false;
}

int main() {

	vector<int> v{-3, 2, 3, 1, 6};
	cout << zeroSumSubarray(v) << endl;
	return 0;
}
