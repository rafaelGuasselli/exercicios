#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, m; cin>>n>>m;
		string s; cin>>s;

		set<int> ind;
		for (int i = 0; i < m; i++) {
			int a; cin>>a;
			ind.insert(a);
		}

		string c; cin>>c;

		sort(c.begin(), c.end());
		int scount = 0;
		for (int i:ind) {
			s[i-1] = c[scount++];
		}	

		cout<<s<<endl;
	}

	return 0;
}