/*

Given an array of positive and negative numbers, find the length of the longest subarray 
(of size at-least one) with 0 sum.

Input: {4, 2, -3, 1, 6}
Output: 3 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: 1 
Explanation:
There is a subarray with zero sum from index 2 to 2.

Input: {-3, 2, 3, 1, 6}
Output: 0

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int lengthOfLongestZeroSumSubarray(vector<int>& v) {
	int prefixSum = 0;
	int max_len = 0; 
	unordered_map<int, int> map;
	for(int j=0; j<v.size(); j++) {
		prefixSum += v[j];

		if(prefixSum == 0) {
			// The subarray from [0....j] is a zero-sum subarray
			max_len = max(max_len, j+1);
		}

		if(map.find(prefixSum) != map.end()) {
			// The subarray from [i+1....j] is a zero-sum subarray
			int i = map[prefixSum];
			max_len = max(max_len, j-i);
		} else {
			map[prefixSum] = j;
		}
	}

	return max_len;
}

int main() {

	vector<int> v{-3, 2, 3, 1, 6};
	cout << lengthOfLongestZeroSumSubarray(v) << endl;
	return 0;
}
