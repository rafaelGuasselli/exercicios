#include<bits/stdc++.h>

using namespace std;

int main() {
	while (1) {
		string n; cin>>n;

		if (n == "0") {
			break;
		}

		long long sp = 0;
		long long si = 0;
		long long total = 0;
		
		for (int i = 0; i < n.size(); i++) {
			int val = n[i]-'0';
			if (i%2 == 0) {
				sp += val;
			} else {
				si += val;
			}
		}

		total = sp-si;
		if (total % 11 == 0) {
			cout<<n<<" is a multiple of 11."<<endl;
		} else {
			cout<<n<<" is not a multiple of 11."<<endl;
		}
	}

	return 0;
}