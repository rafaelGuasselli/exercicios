#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int count = 0;
	while (!cin.eof()) {
		char val; cin>>val;
		if (cin.eof()) {
			break;
		}
		if (val == '4' || val == '7'){
			count++;
		}
	}

	if (count == 0) {
		cout<<"NO"<<endl;
		return 0;
	}

	while (count > 0) {
		if (count%10 != 4 && count%10 != 7) {
			cout<<"NO"<<endl;
			return 0;
		}

		count /= 10;
	}

	cout<<"YES"<<endl;
	return 0;
}