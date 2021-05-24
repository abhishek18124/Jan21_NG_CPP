/*

Given an array of integers nums sorted in ascending order, find the starting and ending position 
of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int lower_bound(vector<int>& nums, int target) {
// 	int s = 0;
// 	int e = nums.size()-1;
// 	int lb = -1;
// 	while(s <= e) {
// 		int m = s + (e-s)/2;
// 		if(nums[m] == target) {
// 			// m may or may not be the first occurrence, so save it
// 			lb = m;
// 			// and move left
// 			e = m-1;
// 		} else if(nums[m] < target) {
// 			s = m+1;
// 		} else {
// 			e = m-1;
// 		}
// 	}
// 	return lb;
// }

// int upper_bound(vector<int>& nums, int target) {
// 	int s = 0;
// 	int e = nums.size()-1;
// 	int ub = -1;
// 	while(s <= e) {
// 		int m = s + (e-s)/2;
// 		if(nums[m] == target) {
// 			// m may or may not be the last occurrence, so save it
// 			ub = m;
// 			// and move right
// 			s = m+1;
// 		} else if(nums[m] < target) {
// 			s = m+1;
// 		} else {
// 			e = m-1;
// 		}
// 	}
// 	return ub;
// }

vector<int> searchRange(vector<int>& nums, int target) {
	// int lb = lower_bound(nums, target);
	// int ub = upper_bound(nums, target);
	auto lb = lower_bound(nums.begin(), nums.end(), target);
	if(lb != nums.end() && *lb == target) {
		// there exists a lower bound for target in nums and that lower
		// bound is the target itself therefore we have an iterator to
		// to the first occurrence of the target
		int i = lb - nums.begin();
		auto ub = upper_bound(nums.begin(), nums.end(), target);
		int j = ub - nums.begin() - 1;
		return {i, j};
	} 	

	// there does not exists a lower bound for target which is equal to target
	return {-1, -1};

}

int main() {

	vector<int> nums{1, 1, 1, 1, 1};
	int target = 2;

	vector<int> out = searchRange(nums, target);
	cout << out[0] << " " << out[1] << endl;

	return 0;
}