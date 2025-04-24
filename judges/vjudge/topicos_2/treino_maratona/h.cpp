#include<bits/stdc++.h>
using namespace std;

int main() {
	int laps, signs; cin>>laps>>signs;
	int total = signs * laps;

	for (int i = 1; i <= 9; i++) {
		cout<<fixed<<setprecision(0);
		cout<<(int)ceil((double)total*i/10);

		if (i < 9) {
			cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}