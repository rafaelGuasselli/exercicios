#include<bits/stdc++.h>

using namespace std;

int memo[2001][2001]; 
string word;

int isPalindrome(int index, int size) {
	for (int i = 0; i < floor(size/2); i++) {
		if (word[index+i] != word[index+size-i-1]) {
			return 0;
		}
	}

	return 1;
}

int getPalindromeSize(int index, int size) {
	if (index < 0 || size <= 0) {
		return 0;
	}

	if (memo[index][size] > 0) {
		return memo[index][size];
	}

	if (isPalindrome(index, size)) {
		memo[index][size] = 1;
		return memo[index][size];
	}

	memo[index][size] = size;
	for (int i = 1; i < size; i++) {
		memo[index][size] = min(memo[index][size], getPalindromeSize(index, i) + getPalindromeSize(index+i, size-i));
		if (memo[index][size] == 2) {
			break;
		}
	}

	return memo[index][size];
}

int main() {
	int size; cin>>size;
	cin>>word;

	cout<<getPalindromeSize(0, size)<<endl;
	return 0;
}