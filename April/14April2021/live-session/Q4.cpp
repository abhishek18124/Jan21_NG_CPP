/*

Given two strings string1 and string2, the task is 
to find the smallest substring in string1 containing all characters of string2 efficiently. 

*/


#include<iostream>
#include<climits>

using namespace std;

string getMinLenWindow(string text, string pattern) {

	int N=text.size();
	int M=pattern.size();

	string window="";
	if(M>N){
		// no window exists
		return window;
	}

	int pattern_freq_map[256]={0};
	for(int i=0; i<M; i++){
		char ch = pattern[i];
		pattern_freq_map[ch]++;
	}

	int window_freq_map[256]={0};

	int i=0; // indicates the start index of my window
	int min_len=INT_MAX;
	int start_idx=-1;
	int cnt=0;
	for(int j=0; j<N; j++) {
		char ch = text[j];
		// expand the window
		window_freq_map[ch]++;

		// check if window if valid. How?
		if(pattern_freq_map[ch]!=0){
			// ch is present in the pattern
			if(window_freq_map[ch]<=pattern_freq_map[ch]){
				cnt++;
			}
		}

		// window, pattern
		// window freq pattern map

		if(cnt==M) {
			// contract/shrink the window to remove unwanted characters

			// 1. if a character is not present in the pattern
			// 2. if a character is present in the pattern but is in excess in the window

			char temp=text[i];
			while(pattern_freq_map[temp]==0 or pattern_freq_map[temp]<window_freq_map[temp]){
				// start shrinking from left
				window_freq_map[temp]--;
				i++;
				temp=text[i];
			}

			int window_len = j - i + 1;
			if(window_len < min_len) {
				min_len = window_len;
				start_idx = i;
			}
		}
	}

	if(start_idx!=-1){
		window=text.substr(start_idx, min_len);
	}

	return window;
}

int main() {

	string text;
	getline(cin, text);

	string pattern;
	getline(cin, pattern);

	string window = getMinLenWindow(text, pattern);
	cout<<window<<" "<<window.size();

	return 0;
}
