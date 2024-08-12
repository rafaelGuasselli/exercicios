#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, t, a; cin>>n>>t>>a;

	if (t > n/2 || a > n/2) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}