/*

Given a string s which consists of lowercase or uppercase letters, return the length 
of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:
	Input: s = "abccccdd"
	Output: 7

Example 2:
	Input: s = "a"
	Output: 1

Example 3:
	Input: s = "bb"
	Output: 2

*/

#include<iostream>
#include<unordered_set>

using namespace std;

int longestPalindrome(string s) {

	int pairCount = 0;
	unordered_set<char> set;
	for(char ch : s) {
		if(set.find(ch) != set.end()) {
			// ch is already present, so I have a found a pair
			set.erase(ch);
			pairCount++;
		} else {
			// ch is not present in the set
			set.insert(ch);
		}
	}

	int length = pairCount * 2;

	if(set.size() > 0) {
		// there are characters with odd number of occurrence
		// we can choose any one as the middle of the palindrome
		length++;
	}

	return length;
}

int main() {


	return 0;
}
