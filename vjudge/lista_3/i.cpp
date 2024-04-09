#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> pos = {1,2,3,4,5,6,7,8};
bool testar(){
	set<int> colunas;
	for (int i = 0; i < 8; i++) {
		colunas.insert(pos[i]);
	}

	if (colunas.size() < 8) {
		return false;
	}

	set<int> diagonaisA;
	set<int> diagonaisB;
	for (int l = 0; l < 8; l++) {
		int c = pos[l];
		diagonaisA.insert(l+c);
		diagonaisB.insert((c-l));
	}

	return diagonaisA.size() == 8 && diagonaisB.size() == 8;
}

int main() {
	set<vector<int>> solucoes;	
	do{
		if(testar()) {
			solucoes.insert(pos);
		}
	} while(next_permutation(pos.begin(), pos.end()));

	string line;
	int count = 1;
	while (true) {
		if (!getline(cin, line)) {
			break;
		}

		if (line.empty()) {
			break;
		}

		stringstream entrada(line);

		int menor = 8;
		int original[8];
		for (int i = 0; i < 8; i++) {
			entrada>>original[i];
		}

		for (auto solucao: solucoes) {
			int diferencas = 0;
			for (int i = 0; i < 8; i++) {
				if (solucao[i] != original[i]) {
					diferencas++;
				} 
			}

			menor = min(menor, diferencas);
		}

		cout<<"Case "<<count<<": "<<menor<<endl;
		count++;
	}	

	return 0;
}