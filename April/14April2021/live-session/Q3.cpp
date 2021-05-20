/*

Given a digit sequence, generate the possible decodings of the given digit sequence. 

Let, 
	
	1  represent ‘A’ 
    2  represent ‘B’
    .
    .
    .
    26 represent ‘Z’ 

 It may be assumed that the input contains valid digits from 0 to 9 and 
 there are no leading 0’s, no extra trailing 0’s, and no two or more consecutive 0’s.

*/

#include<iostream>

using namespace std;

void generateDecodings(char* inp, char* out, int i, int j) {

	// Have I reached the end of the input array
	if(inp[i]=='\0'){
		// terminate and print the output
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	// I am standing at the ith digit of the inp and I have to make a decision

	// A. decode only the ith digit

	// A.1 extract the ith digit from the input
	int digit = inp[i] - '0'; // '2' - '0' -> 50 - 48 = 2

	if(digit!=0){

		// A.2 map the ith digit to its character
		char ch  = digit + 'A' - 1; // 1 + 'A' - 1 = 1 + 65 - 1 = 65 = 'A'
									// 2 + 'A' - 1 = 2 + 65 - 1 = 66 = 'B'

		// 1 -> 'A' ? 1 + 'A' - 1 = 1 + 65 - 1 = 65 = 'A'
		// 2 -> 'B' ? 2 + 'A' - 1 = 2 + 65 - 1 = 66 = 'B'

		// A.3 write the ch to the jth index of out
		out[j]  = ch;

		// A.4 recursion
		generateDecodings(inp, out, i+1, j+1);
	 
		// B. form a number using ith and (i+1)th digit and decode it

		if(inp[i+1]!='\0') {
			// B.1 extract the (i+1)th digit
			int next_digit = inp[i+1] - '0';

			// B.2 form a number using the ith and (i+1)th digit
			int number = digit * 10 + next_digit; // 1, 2 = 1*10 + 2 = 12

			if(number<=26) {
				// B.3 map the number to its character
				ch = number + 'A' - 1;

				// B.4 update the jth index of out
				out[j] = ch;

				// B.5 recusion
				generateDecodings(inp, out, i+2, j+1);
			}
		}
	}

	return;

}

int main() {

	char inp[100];
	cin>>inp;

	char out[100];

	generateDecodings(inp, out, 0, 0);

	return 0;
}