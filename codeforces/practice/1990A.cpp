#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;

		map<int, int> val;
		for (int i = 0; i < n; i++) {
			int a; cin>>a;
			if (val.find(a) == val.end()) {
				val[a] = 0;
			}
			
			val[a]++;
		}

		int count = 0;
		for (pair<int, int> v: val) {
			if (v.second%2 == 1) {
				count = 1;
				break;
			}
		}


		if (count%2 == 1) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}