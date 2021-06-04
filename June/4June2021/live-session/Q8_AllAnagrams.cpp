/*

Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

Example 1:
	Input: s = "cbaebabacd", p = "abc"
	Output: [0,6]

Example 2:
	Input: s = "abab", p = "ab"
	Output: [0,1,2]

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> getRepresentation(string& str, int i, int j) {
	vector<int> repr(26, 0);
	for(int k=i; k<=j; k++) {
		char ch = str[k];
		repr[ch-'a']++;
	}
	return repr;
}

vector<int> findAnagrams(string s, string p) {

	if(s.size() < p.size()) return {};

	vector<int> out;
	vector<int> pRepr = getRepresentation(p, 0, p.size()-1);
	vector<int> sRepr = getRepresentation(s, 0, p.size()-1);
	if(sRepr == pRepr) out.push_back(0);

	for(int i=1; i<=s.size()-p.size(); i++) {
		int j = i+p.size()-1;
			
		char oldChar = s[i-1];
		char newChar = s[j];

		sRepr[oldChar-'a']--;
		sRepr[newChar-'a']++;

		if(sRepr == pRepr) out.push_back(i);
	}

	return out;
	
}

int main() {

	vector<int> out = findAnagrams("abab", "ab");
	for(auto i : out) cout << i << " ";
	return 0;
}