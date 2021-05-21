/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once 
put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the 
stalls, such that the minimum distance between any two of them is as large as possible. 

What is the largest minimum distance?

Input Format
First line contains N and C, separated by a single space, representing the total number of stalls 
and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Constraints
2 <= N <= 100,000
0 <= xi <= 1,000,000,000
2 <= C <= N

Output Format
Print one integer: the largest minimum distance.
*/

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

bool canPlaceCows(int N, int C, int* stalls, int m) {
	// place the 1st cow in the 1st stall
	int prevCowPosition = stalls[0];
	int numCowsPlaced = 1;
	for(int i=1; i<N; i++) {
		// can you place the next cow at the ith stall?
		if(stalls[i]-prevCowPosition >= m) {
			// you can place the next cow at the ith stall
			prevCowPosition = stalls[i];
			numCowsPlaced++;
			if(numCowsPlaced == C) {
				return true;
			}
		}
	}
	return false;
}

int findMaxMinDist(int N, int C, int* stalls) {
	int s = 0; // place the cows in the same stall
	// int e = stalls[N-1]-stalls[0]; // place the cows at the extreme ends 
	int e = INT_MAX;
	int ans;

	while(s <= e) {
		int m = s + (e-s)/2;
		// can you place C cows in N stalls such that the min. dist. between cows is m?
		if(canPlaceCows(N, C, stalls, m)) {
			ans = m;
			s = m+1;
		} else {
			e = m-1;
		}
	}

	return ans;

}

int main() {

	int t;
	cin >> t;

	while(t--) {
		int N;
		cin >> N;

		int C;
		cin >> C;

		int* stalls = new int[N];
		for(int i=0; i<N; i++) 
			cin >> stalls[i];

		sort(stalls, stalls+N);

		cout << findMaxMinDist(N, C, stalls) << endl;
	}

	return 0;
}
