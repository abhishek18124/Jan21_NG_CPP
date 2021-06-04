/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

	Example 1:
		Input: s = "anagram", t = "nagaram"
		Output: true

	Example 2:
		Input: s = "rat", t = "car"
		Output: false

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> getRepresentation(string& s) {
	vector<int> repr(26, 0);
	for(char ch : s) {
		repr[ch-'a']++;
	}
	return repr;
}

int main() {

	string s("anagram");
	string t("nagaram");

	vector<int> sRepr = getRepresentation(s);
	vector<int> tRepr = getRepresentation(t);

	// for(int i=0; i<26; i++) 
	// 	cout << sRepr[i] << " ";

	// cout << endl;

	// for(int i=0; i<26; i++) 
	// 	cout << tRepr[i] << " ";

	cout << (sRepr == tRepr) << endl;

	return 0;
}