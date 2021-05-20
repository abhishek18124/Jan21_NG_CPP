/*

Given a sorted array nums, remove the duplicates in-place such that each element appears only once 
and returns the new length.

*/

#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {

	int i=-1;
	for(int j=0; j<nums.size(); j++) {
		nums[++i] = nums[j];
		while(j < nums.size()-1 && nums[j] == nums[j+1]) {
			j++;
		}
	}
	return i+1;
}

int main() {

	vector<int> nums{1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7};
	int len = removeDuplicates(nums);
	for(int i=0; i<len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}