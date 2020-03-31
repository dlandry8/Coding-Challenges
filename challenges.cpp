#include "challenges.h"

void palindromes(char*);

int main(int argc, char* argv[]) {
	/*
	Palindromes 3/30/2020
	*/
	if (argc >= 2)
		palindromes(argv[1]);
}

void palindromes(char* input) {
	vector<string> myPalindromes = seek_palindromes(input);
	for (int i = 0; i < myPalindromes.size(); i++)
		cout << myPalindromes[i] << endl;
}