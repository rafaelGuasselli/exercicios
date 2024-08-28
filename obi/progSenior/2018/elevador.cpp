#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> caixas(n);
	for (int i = 0; i < n; i++) {
		cin>>caixas[i];
	}

	sort(caixas.begin(), caixas.end());
	
	int possible = 1;
	int previous = 0;
	for (int value: caixas) {
		if (value-previous > 8) {
			possible = 0;
			break;
		}

		previous = value;
	}

	if (possible) {
		cout<<"S"<<endl;
	} else {
		cout<<"N"<<endl;
	}

	return 0;
}