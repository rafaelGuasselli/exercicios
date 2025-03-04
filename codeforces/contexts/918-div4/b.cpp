#include<bits/stdc++.h>
//#define int long long
using namespace std;

int freq[3];
signed main() {
	int t; cin>>t;
	while (t--) {
		memset(freq, 0, sizeof(int) * 3);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char val; cin>>val;
				int index = val-'A';
				if (index >= 0 && index < 3) {
					freq[index]++;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (freq[i] == 2) {
				cout<<(char)('A'+i)<<endl;
				break;
			}
		}
	}

	return 0;
}