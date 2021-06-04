/*

Rearrange an array

Given an array arr[] of size n where every element is in the range from 0 to n-1. 
Rearrange the given array so that arr[i] becomes arr[arr[i]].

Example :
	
	Input : arr[] = {4,0,2,1,3}
	Output: arr[] = {3,4,2,0,1}

*/

#include<iostream>

using namespace std;

void rearrange(int arr[], int n) {

	for(int i=0; i<n; i++) {
		arr[i] += (arr[arr[i]]%n)*n;
	}

	for(int i=0; i<n; i++) {
		arr[i] = arr[i]/n;
		cout << arr[i] << " ";
	}
}

int main() {

	int arr[] = {4,0,2,1,3};
	rearrange(arr, 5);
	return 0;
}