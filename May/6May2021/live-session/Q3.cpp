/*

There is an integer array nums sorted in ascending order (with distinct values). Prior to being passed to 
your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting 
array is  [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 

For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target 
if it is in nums, or -1 if it is not in nums.

*/

#include<iostream>
#include<vector>

using namespace std;

int search(int n, int* a, int t) {

	int s = 0;
	int e = n-1;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(a[m] == t) 
			return m;

		if(a[s] <= a[m]) {
			// m lies in the first plane
			if(t >= a[s] && t < a[m]) {
				e = m-1;
			} else {
				s = m+1;
			}
		} else {
			// m lies in the second plane
			if(t <= a[e] && t > a[m]) {
				s = m+1;
			} else {
				e = m-1;
			}
		}

	}

	return -1;
}

int main() {

	int n;
	cin >> n;

	int* a = new int[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int t;
	cin >> t;

	cout << search(n, a, t) << endl;
	
	return 0;
}