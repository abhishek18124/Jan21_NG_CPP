/*

Write a function that reverses a string.

*/

#include<iostream>
#include<vector>

using namespace std;

void reverseString(vector<char>& s) {
	// reverse(s.begin(), s.end());
	int i=0;
	int j=s.size()-1;

	while(i < j ) {
		// char temp = s[i];
		// s[i] = s[j];
		// s[j] = temp;

		// swap(s[i], s[j]);

		// without temp

		// s[i] = s[i]^s[j];
		// s[j] = s[i]^s[j];
		// s[i] = s[i]^s[j];

		s[i] = s[i]+s[j];
		s[j] = s[i]-s[j];
		s[i] = s[i]-s[j];

		i++;
		j--;
	}
}

int main() {

	vector<char> s{'a', 'b', 'c', 'd', 'e'};
	reverseString(s);
	for(int i=0; i<s.size();i++) cout << s[i] ;
	cout << endl;

	// int x = 10;
	// int y = 5;

	// x = x*y;
	// y = x/y;
	// x = x/y;

	// cout << x << endl << y << endl;


	return 0;
}