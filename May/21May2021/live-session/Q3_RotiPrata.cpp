/*

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for 
the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank 
R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R 
minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will 
cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes 
hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does 
not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the 
order done. Please write a program to help him out.

 
Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line 
of the test case we have P the number of prata ordered. In the next line the first integer denotes 
the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

*/

#include<iostream>
#include<climits>

using namespace std;

int numPratasByACook(int rank, int timeLimit) {
	int cnt=0;
	int i=1;
	int time=0;
	while(time <= timeLimit) {
		time += i*rank;
		if(time>timeLimit)
			break;
		cnt++;
		i++;
	}
	return cnt;
}

int numPrataCooked(int L, int* ranks, int timeLimit) {
	int numPratas=0;
	for(int i=0; i<L; i++) {
		numPratas += numPratasByACook(ranks[i], timeLimit);
	}
	return numPratas;
}

int minTimeToGetOrder(int P, int L, int* ranks) {
	// note : when you don't use the tightest lower & upper bounds
	// you will make more comparisions during binary search.

	// so, always try to find the tightest bounds, if not possible
	// go with general valid bounds.

	int s = 0; // time cannot be less than 0
	int e = INT_MAX; 
	int ans;

	while(s <= e) {
		int m = s + (e-s)/2;
		// Can L cooks complete the order of P pratas in 'm' amount of time 
		if(numPrataCooked(L, ranks, m) >= P) {
			ans = m;
			e = m - 1;
		} else {
			s = m + 1;
		}
	}

	return ans;
}

int main() {

	int t;
	cin >> t;

	int P;
	int L;
		
	while(t--) {
		cin >> P;

		cin >> L;

		int* ranks = new int[L];
		for(int i=0; i<L; i++) 
			cin >> ranks[i];

		cout << minTimeToGetOrder(P, L, ranks) << endl;
	}

	return 0;
}
