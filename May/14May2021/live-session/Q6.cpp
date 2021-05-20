/*

Given a stream of characters and we have to find first non repeating character each time a character is 
inserted to the stream.

Examples:

Input  : a a b c
Output : a -1 b b

Input  : a  a c
Output : a -1 c

*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> queue;
	int freqMap[26]={0};

	char ch;
	cin >> ch;

	while(ch != '.') {
		if(freqMap[ch-'a'] < 1) queue.push(ch);
		freqMap[ch-'a']++;

		while(!queue.empty() && freqMap[queue.front()-'a'] > 1) 
			queue.pop();

		if(queue.empty())
			cout << -1 << " ";
		else 
			cout << queue.front() << " ";

		cin >> ch;
	}

	return 0;
}