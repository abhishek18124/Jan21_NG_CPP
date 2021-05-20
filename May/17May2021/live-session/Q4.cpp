/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
	Input: num1 = "2", num2 = "3"
	Output: "6"

Example 2:
	Input: num1 = "123", num2 = "456"
	Output: "56088"

*/

#include<iostream>
#include<vector>

using namespace std;

string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();

	string out(len1+len2, '0'); // this will create a string of size len1+len2 initialised with '0'
	for(int i=len1-1; i>=0; i--) {
		for(int j=len2-1; j>=0; j--) {
			int prod = (num1[i]-'0') * (num2[j]-'0');
			int pos1 = i+j;
			int pos2 = i+j+1;

			int sum = (out[pos2]-'0') + prod;
			out[pos2] = sum%10 + '0';
			out[pos1] = ((out[pos1] - '0') + sum/10) + '0';
		}
	}

	// removing leading zeros
	size_t startPos = out.find_first_not_of('0');
	return startPos == string::npos ? "0" : out.substr(startPos);
}

int main() {

	return 0;
}