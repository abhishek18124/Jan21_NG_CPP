/*

Given an array of positive and negative numbers, find the length of the longest subarray 
(of size at-least one) with K sum.

Input: {4, 2, -3, 1, 6}, K = 4
Output: 4 

Input: {-3, 2, 3, 1, 6, 2}, K = 6
Output: 3

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int lengthOfLongestKSumSubarray(vector<int>& v, int k) {
	int prefixSum = 0;
	int max_len = 0; 
	unordered_map<int, int> map;
	for(int j=0; j<v.size(); j++) {
		prefixSum += v[j];

		if(prefixSum == k) {
			// The subarray from [0....j] is a k-sum subarray
			max_len = max(max_len, j+1);
		}

		if(map.find(prefixSum-k) != map.end()) {
			// The subarray from [i+1....j] is a zero-sum subarray
			int i = map[prefixSum-k];
			max_len = max(max_len, j-i);
		} else {
			map[prefixSum] = j;
		}
	}

	return max_len;
}


int main() {

	vector<int> v{-3, 2, 3, 1, 6, 2};
	cout << lengthOfLongestKSumSubarray(v, 6) << endl;
	return 0;
}
