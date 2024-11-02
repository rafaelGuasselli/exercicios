#include<bits/stdc++.h>
#define int long long

using namespace std;
string digits;
int smaller;
int n; 

void solve(int index, int total, int doubleDigit) {
	if (index == n) {
		if(doubleDigit) {
			smaller = min(smaller, total);
		}

		return;
	}

	int val = digits[index]-'0';
	if (!doubleDigit && index < n-1) {
		int val2 = digits[index+1]-'0';
		if(total <= 1 || (val * 10 + val2) <= 1) {
			solve(index+2, total * (val * 10 + val2), 1);
		} else {
			solve(index+2, total + (val * 10 + val2), 1);
		}
	} 

	if(total <= 1 || val <= 1) {
		solve(index+1, total*val, doubleDigit);
	} else {
		solve(index+1, total+val, doubleDigit);
	}
}

signed main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		cin>>n;
		cin>>digits;
		
		smaller = 1e18;
		int val1 = digits[0]-'0';
		int val2 = digits[1]-'0';
		
		solve(1, val1, 0);
		solve(2, val1*10+val2, 1);
		cout<<smaller<<endl;
	}

	return 0;
}