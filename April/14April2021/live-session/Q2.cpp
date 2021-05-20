/*

Given an amount and the denominations of coins available, 
determine how many ways change can be made for amount. 

There is a limitless supply of each coin type.

*/

#include<iostream>
#include<set>

using namespace std;

void countCoinChange(int N, int* coins, int M, int i, multiset<int>& ms) {

	if(N==0) {
		// I have found a coin change
		cout<<"{";
		for(multiset<int>::iterator it=ms.begin(); it!=ms.end(); it++){
			cout<<*it<<" ";
		}
		cout<<"}"<<endl;
		// return 1;
		return;
	}

	if(N<0) {
		// I have a in-valid coin change
		// return 0;
		return;
	}

	if(i==M && N>0){
		// I have no coin configuration
		// return 0;
		return;
	}

	// I am standing at the ith coin and I have to make a decision. What decision?

	// include ith coin to the change configuration
	ms.insert(coins[i]);
	// int X = countCoinChange(N-coins[i], coins, M, i, ms);
	countCoinChange(N-coins[i], coins, M, i, ms);


	// do not include the ith coin to the change configuration
	ms.erase(ms.lower_bound(coins[i]));
	// int Y = countCoinChange(N, coins, M, i+1, ms);
	countCoinChange(N, coins, M, i+1, ms);

	// return X + Y;
	return;

}

int main() {

	// read amount from the user
	int N;
	cin>>N;	

	// read number of coins
	int M;
	cin>>M;

	int* coins = new int[M];
	for(int i=0; i<M; i++){
		cin>>coins[i];
	}

	multiset<int> ms;

	// cout <<	countCoinChange(N, coins, M, 0, ms) << endl;
	countCoinChange(N, coins, M, 0, ms);

	return 0;
}