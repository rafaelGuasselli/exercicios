#include<bits/stdc++.h>
#define max(a, b) a > b ? a : b 
#define min(a, b) a > b ? b : a 
//#define int long long
using namespace std;
 
int chars[30];
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		memset(chars, 0, sizeof(int) * 30);

		int diff = 0;
		char prev = '.';
		int success = 0;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == prev) {
				success = 1;
				cout<<s.substr(i-1, 2)<<endl;
				break;
			} 
			
			diff += max(0, 1-chars[c-'a']);
			chars[c-'a'] = 1;

			if (diff == 3) {
				success = 1;
				cout<<s.substr(i-2, 3)<<endl;
				break;
			}

			prev = c;
		}

		if (!success) {
			cout<<-1<<endl;
		}
	}
	return 0;
}