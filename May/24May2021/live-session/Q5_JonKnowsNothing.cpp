/*

Jon recently started taking programming classes. His friends say "Jon knows nothing!". 
But Jon wants to prove them wrong by completing the following task.

He was given a string A and three substring D, E, and F. He has to find the substrings
D or E or F in A and either remove them or leave them as it is.

If D or E or F is removed from the given string, then he gets a new string A1. This process
is repeated on A1 to get A2 and so on till the process is not possible.

Let the final string be Af.

Help Jon in determining minimum possible length of final string.

Example 1
	Input : A = "aaabccd" ; D = "abc" ; E = "ac" ; F = "aaa"
	Output : 2

Example 2	
	Input  : A = "abcdefabcd" ; D = "ab" ; E = "cd" ; F = "e"
	Output : 1

*/

#include<iostream>
#include<climits>

using namespace std;

int minLength=INT_MAX;

void findMinLength(string A, string D, string E, string F) {

	size_t idx_D = A.find(D);
	size_t idx_E = A.find(E);
	size_t idx_F = A.find(F);

	// base case

	if(idx_D == string::npos && idx_E == string::npos && idx_F == string::npos) {
		// none of the substrings are present in A, you have reached Af.
		minLength = min(minLength, int(A.size()));
		return;
	}
	
	if(idx_D != string::npos) {
		string temp(A); 
		temp.erase(idx_D, D.size()); // temp = A-D
		findMinLength(temp, D, E, F);
	}

	if(idx_E != string::npos) {
		string temp(A);
		temp.erase(idx_E, E.size()); // temp = A-E
		findMinLength(temp, D, E, F);
	}

	if(idx_F != string::npos) {
		string temp(A);
		temp.erase(idx_F, F.size());
		findMinLength(temp, D, E, F); // temp = A-F
	}

	return;

}

int main() {

	// string A("aaabccd");
	// string D("abc");
	// string E("ac");
	// string F("aaa");
	
	string A("abcdefabcd");
	string D("ab");
	string E("cd");
	string F("e");

	findMinLength(A, D, E, F);

	cout << minLength << endl;

	return 0;
}
