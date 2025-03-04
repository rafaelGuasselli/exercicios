#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	int posI = 0;
	int posJ = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int val; cin>>val;
			if (val == 1) {
				posI = abs(i-2);
				posJ = abs(j-2);
			}
		}
	}

	cout<<posI+posJ<<endl;
	return 0;
}