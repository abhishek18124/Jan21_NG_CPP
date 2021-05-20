/*


Given an array of integers (both odd and even), the task is to arrange them 
in such a way that odd and even values come in alternate fashion 
in non-decreasing order(ascending) respectively.

If the smallest value is Even then we have to print Even-Odd pattern.
If the smallest value is Odd then we have to print Odd-Even pattern.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin>>n;

	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	sort(arr, arr+n);

	vector<int> even;
	vector<int> odd;

	for(int i=0; i<n; i++){
		if(arr[i]%2==0){
			even.push_back(arr[i]);
		} else {
			odd.push_back(arr[i]);
		}
	}

	bool evenFlag=false;
	if(arr[0]%2==0){
		// smallest element is even therefore print even-odd pattern
		evenFlag=true;
	} else {
		// print odd-even pattern
	}

	int i=0;
	int j=0;

	for(int k=0; k<n; k++){
		if(evenFlag){
			arr[k] = even[i];
			i++;
			evenFlag=!evenFlag;
		} else {
			arr[k] = odd[j];
			j++;
			evenFlag=!evenFlag;
		}
	}


	// print the pattern
	for(int k=0; k<n; k++) {
		cout<<arr[k]<<" ";
	}	

	return 0;
}