#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;

	int substituir = 0;
	int consertar = 0;
	int bom = 0;

	for (int i = 0; i < n; i++) {
		int val; cin>>val;
		if (val < 50) {
			substituir++;
		} else if (val < 85) {
			consertar++;
		} else {
			bom++;
		}
	}

	cout<<substituir<<" "<<consertar<<endl;
	return 0; 
}