/*

Given two arrays of integers, compute the pair of values (one value in each array) 
with the smallest (non-negative) difference. Return the difference.
 
Input : A[] = {l, 3, 15, 11, 2}
        B[] = {23, 127, 235, 19, 8} 
Output : 3  
That is, the pair (11, 8) 

Input : A[] = {l0, 5, 40}
        B[] = {50, 90, 80} 
Output : 10
That is, the pair (40, 50)

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int main() {

	vector<int> A{10, 5, 40};
	vector<int> B{50, 90, 80};

	sort(B.begin(), B.end());

	int minAbsDiff = INT_MAX;
	for(int i=0; i<A.size(); i++) {
		auto lb = lower_bound(B.begin(), B.end(), A[i]);
		if(lb != B.end()) {
			// there exists lower bound of A[i] in B.
			int j = lb - B.begin();
			minAbsDiff = min(minAbsDiff, abs(A[i]-B[j]));
			if(j>0) minAbsDiff = min(minAbsDiff, abs(A[i]-B[j-1]));
		} else {
			// there does not exists a lower bound of A[i] in B.
			// so the element in B which is the closes to A[i] is the
			// last element of B.
			minAbsDiff = min(minAbsDiff, abs(A[i]-B[B.size()-1]));
		}
	}

	cout << minAbsDiff << endl;

	return 0;
}
