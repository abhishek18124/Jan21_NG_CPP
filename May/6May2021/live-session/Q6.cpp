/*

The Hamming distance between two integers is the number of positions at which 
the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

*/

#include<iostream>

using namespace std;

int hammingDistance(int x, int y) {

	int distance = 0;
	for(int i=0; i<32; i++) {
		int mask  = 1<<i;
		int x_bit = x & mask ? 1 : 0;
		int y_bit = y & mask ? 1 : 0;
		if(x_bit != y_bit) distance++; 
	}
	return distance;
}

int countSetBits(int z) {

	int cnt=0;
	for(int i=0; i<32; i++) {
		int mask = 1<<i;
		if(z&mask){
			cnt++;
		}
	}
	return cnt;
}

int countSetBitsEfficient(int z) {
	int cnt=0;
	while(z > 0) {
		z = z&(z-1);
		cnt++;
	}
	return cnt;
}

int main() {

	int x;
	cin >> x;

	int y;
	cin >> y;

	cout << hammingDistance(x, y) << endl;
	cout << countSetBits(x^y) << endl;
	cout << __builtin_popcount(x^y) << endl;
	cout << countSetBitsEfficient(x^y) << endl;

	return 0;
}