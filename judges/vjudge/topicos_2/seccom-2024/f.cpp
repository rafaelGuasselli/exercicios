	#include <bits/stdc++.h>
	#define int long long
	#define ll long long
	#define pii pair<long long, long long>
	using namespace std;

	signed main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		int a, p, v; cin>>a>>p>>v;
		int total = p * v;
		total = total - a;
		cout<<2*total/v<<endl;
	}