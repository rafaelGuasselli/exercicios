#include<bits/stdc++.h>

using namespace std;

int memo[2001][2001]; 
int isPalindrome(string a) {
	for (int i = 0; i < floor(a.size()/2); i++) {
		if (a[i] != a[a.size()-i-1]) {
			return 0;
		}
	}

	return 1;
}

string word;
int getPalindromeSize(int start, int size) {
	if (start < 0 || size <= 0) {
		return 0;
	}

	if (memo[start][size] > 0) {
		return memo[start][size];
	}

	string substring = word.substr(start, size);
	if (isPalindrome(substring)) {
		memo[start][size] = 1;
		return memo[start][size];
	}

	memo[start][size] = substring.size();
	for (int i = 1; i < substring.size(); i++) {
		memo[start][size] = min(memo[start][size], getPalindromeSize(start, i) + getPalindromeSize(start+i, size-i));
	}

	return memo[start][size];
}

int main() {
	int size; cin>>size;
	cin>>word;

	for (int s = 1; s <= size; s++) {
		for (int i = 0; i < size; i++) {
			string substring = word.substr(i, s);
			if (isPalindrome(substring)) {
				memo[i][s] = 1;
				continue;
			}

		}
	}

	return 0;
}