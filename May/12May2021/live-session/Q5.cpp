/*

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then 
converted into a different digit string. To determine how you "say" a digit string, split it 
into the minimal number of groups so that each group is a contiguous section all of the same 
character. Then for each group, say the number of characters, then say the character. 

To convert the saying into a digit string, replace the counts with a number and concatenate 
every saying.

*/

#include<iostream>

using namespace std;

string say(string str) {
	string ans="";
	for(int i=0; i<str.size(); i++) {
		char ch = str[i];
		int count = 1;
		while(i < str.size()-1 && str[i] == str[i+1]) {
			count++;
			i++;
		}
		ans += count + '0';
		ans += ch;
	}
	return ans;
}

string countAndSay(int n) {
	if(n==1) return "1";
	return say(countAndSay(n-1));
}

int main() {

	for(int i=1; i<10; i++)
		cout << countAndSay(i) << endl;
	return 0;
}