#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		string op; cin>>op;
		if (op.find('+') != string::npos) {
			x++;
		} else {
			x--;
		}
	}

	cout<<x<<endl;
	return 0;
}