
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> getDigitsAtBase(int n, int b) {
	vector<int> digits;
	for (int i = log(n)/log(b); i >= 0; --i) {
		int weight = (int)pow(b, i);
		digits.push_back(n / weight);
		n = n % weight;
	} 
	
	return digits;
}

bool checkPalindrome(const vector<int>& s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin>> n;
	set<int> bases;

	for (int d = 1; d * d <= n+1; d++) {
		int b = (n/d) -1;
		if (d*b+d == n && b > 1 && d < (b-1)) {
			bases.insert(b);
		}
	}

	for (int b = 2; b * b <= n+1; b++) {
		vector<int> digits = getDigitsAtBase(n, b);
		if (checkPalindrome(digits)) {
			bases.insert(b);
		}
	}

	if (bases.size() == 0) {
		cout<<"*"<<endl;
	} else {
		auto it = bases.begin();
		for (int i = 0; i < bases.size(); i++) {
			if (i > 0) {
				cout<<" ";
			}

			cout<<*it;
			it++;
		}
		cout<<endl;
	}

	return 0;
}