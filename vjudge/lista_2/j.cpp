#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int qtdTestes; cin>>qtdTestes;

	for (int i = 0; i < qtdTestes; i++) {
		int qtdAmigos; cin>>qtdAmigos;
		int unicoAmigos[qtdAmigos] = {0};
		map<int, set<int>> selos;

		for(int j = 0; j < qtdAmigos; j++) {
			int qtdSelos; cin>>qtdSelos;
			
			for (int k = 0; k < qtdSelos; k++) {
				int selo; cin>>selo;
				selos[selo].insert(j);
			}
		}

		double totalUnicos = 0;
		for(auto selo:selos){
			if ((selo.second).size() == 1) {
				unicoAmigos[*(selo.second).begin()] += 1;
				totalUnicos += 1;
			}
		}

		cout<<fixed;
		cout<<setprecision(6);
		cout<<"Case "<<i+1<<": ";
		for (int w = 0; w < qtdAmigos; w++) {
			double percentual = unicoAmigos[w]/totalUnicos * 100;
			cout<<percentual<<"%";

			if (w+1!=qtdAmigos) {
				cout<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}