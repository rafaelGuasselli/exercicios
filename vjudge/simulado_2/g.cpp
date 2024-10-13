#include<bits/stdc++.h>

using namespace std;


int main() {
	int n; cin>>n;
	set<int> towers;
	
	for (int i = 0; i < n; i++) {
		int a; cin>>a;
		towers.insert(a);
	}

	vector<int> results;
	int anterior = 0;
	int trocas = 0;
	int comeca = 0;
	int ant = 1;

	for (int i:towers) {
		if ((i-anterior) > 1) {
			trocas++;
		}

		if ((i-anterior) == 1 && ant == 0) {
			ant = 1;
		} else if ((i-anterior == 1) && ant == 1) {
			comeca++;
			trocas = 0;
		} else {
			ant = 0;
		}

		anterior = i;
	}


	if ((trocas)%2 == comeca%2) {
		cout<<"Alicius"<<endl;
	} else {
		cout<<"Bobius"<<endl;
	}

	return 0;
}