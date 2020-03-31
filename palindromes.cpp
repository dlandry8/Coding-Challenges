/*
From Daily Coding Problem (founders@dailycodingproblem.com):

	Good morning! Here's your coding interview problem for today.

	This problem was asked by Google.

	Given a string, split it into as few strings as possible such that each string is a palindrome.

	For example, given the input string racecarannakayak, return ["racecar", "anna", "kayak"].

	Given the input string abc, return ["a", "b", "c"].
	
An original solution by David Landry
Completed Mar. 30, 2020
*/

#include "challenges.h"

using namespace std;

// seek_palindromes is the method called by main
vector<string> seek_palindromes(string input) {
	// Though there may be algorithms that can do this more efficiency, there is an easy way
	// to do this in O(n^3) time. 
	string tempString = "";
	vector<string> palindromes;
	for (int i = 0; i < input.length(); i += tempString.length()) {
		string substring = "";
		tempString = input[i];
		// Find the longest possible palindrome from starting position i, storing the palindrome in
		//	tempString. The above for statement will then increment i to the next position after the
		//	longest palindrome.
		for (int j = i; j < input.length(); j++) {
			substring += input[j];
			if (is_palindrome(substring))
				tempString = substring;
		}
		palindromes.push_back(tempString);
	}
	return palindromes;
}


// is_palindrome is a helper method called by seek_palindromes
bool is_palindrome(string input) {
	queue<char> testerBack;
	for (int i = 0; i <= input.length() / 2; i++) {
		testerBack.push(input[i]);
	}
	for (int i = input.length() - 1; i > input.length() / 2 - 1; i--) {
		if (testerBack.front() != input[i])
			return false;
		testerBack.pop();
	}
	return true;
}