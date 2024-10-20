#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int val; cin>>val;
		sum += val;
	}

	if (sum > 0) {
		cout<<"HARD"<<endl;
	} else {
		cout<<"EASY"<<endl;
	}
	return 0;
}