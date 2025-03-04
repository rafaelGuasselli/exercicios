#include<bits/stdc++.h>
	
using namespace std;
	
int main() {
	int nTests; cin>>nTests; 
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;
		string s; cin>>s;
		if (s[0] != s[n-1]) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}