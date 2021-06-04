/*

Given two equal-size strings s and t. In one step you can choose any character of t and 
replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different 
(or the same) ordering.

Example 1:
	Input: s = "bab", t = "aba"
	Output: 1
	Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
	Input: s = "leetcode", t = "practice"
	Output: 5
	Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to 
				 make t anagram of s.

*/

#include<iostream>

using namespace std;

vector<int> getRepresentation(string& s) {
    vector<int> repr(26, 0);
    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        repr[ch-'a']++;
    }
    return repr;
}

int minSteps(string s, string t) {
    vector<int> sRepr = getRepresentation(s);
    vector<int> tRepr = getRepresentation(t);
    
    int minSteps = 0;
    for(int i=0; i<26; i++) {
        if(tRepr[i] > sRepr[i]) {
            minSteps += (tRepr[i]-sRepr[i]);
        }
    }
    
    return minSteps;
}


int main() {

	string s("bab");
	string
	return 0;
}