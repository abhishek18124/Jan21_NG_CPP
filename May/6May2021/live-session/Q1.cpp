/*

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the 
maximum frequency of any one of its elements. Your task is to find the smallest possible length of 
a (contiguous) subarray of nums, that has the same degree as nums.

Example 1 :

	Input: nums = [1,2,2,3,1]
	Output: 2
	Explanation: 
	The input array has a degree of 2 because both elements 1 and 2 appear twice.
	Of the subarrays that have the same degree:
	[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
	The shortest length is 2. So return 2.

Example 2 :

	Input: nums = [1,2,2,3,1,4,2]
	Output: 6
	Explanation: 
	The degree is 3 because the element 2 is repeated 3 times.
	So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

Approach 1 - O(N^2)
Approach 2 - O(N)

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findShortestSubArray(vector<int>& nums) {

	int degree = 0;
	unordered_map<int, pair<int, pair<int, int>>> map;
	for(int i=0; i<nums.size(); i++) {
		if(map.find(nums[i]) == map.end()) {
			// nums[i] has occurred for the first time
			map[nums[i]].first = 1; //frequency
			map[nums[i]].second.first = i; // first occurrence
			map[nums[i]].second.second = i; // last occurrence
		} else {
			map[nums[i]].first++; // frequency
			map[nums[i]].second.second = i; // last occurrrence
		}
		degree = max(degree, map[nums[i]].first);
	}

	// for(auto p : map) {
	// 	cout << p.first << " " << p.second.first << " " << p.second.second.first << " " << p.second.second.second << endl;
	// }

	int minLen = nums.size();
	for(auto p : map) {
		if(p.second.first == degree) 
			minLen = min(minLen, p.second.second.second - p.second.second.first + 1);
	
	}

	return minLen;

}

int main() {

	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i=0; i<n; i++)
		cin >> nums[i];

	cout << findShortestSubArray(nums) << endl;

	return 0;
}
