#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string, string> dicionario;
set<string> traducoes;
string palavra;

void buscar(int index, string atual) {
	if (traducoes.size() == 100) {
		return;
	}

	if(index == palavra.size()) {
		traducoes.insert(atual);
		return;
	} 
	
	vector<pair<int, string>> proximos;
	string sozinho, dupla, extra; 
	
	sozinho = palavra.substr(index, 1);
	if (dicionario.find(sozinho) != dicionario.end()) {
		proximos.push_back(make_pair(index+1,  atual+dicionario[sozinho]));
	}

	if (index < palavra.size()-1) {
		dupla = palavra.substr(index, 2);
		if (dicionario.find(dupla) != dicionario.end()) {
			proximos.push_back(make_pair(index+2, atual+dicionario[dupla]));
		}
	} 

	if (sozinho == "0" && index < palavra.size()-1) {
		extra = palavra.substr(index+1, 1);
		proximos.push_back(make_pair(index+1, atual));
	}

	sort(proximos.begin(), proximos.end(), [](pair<int, string> &a, pair<int, string> &b){ 
		return a.second.compare(b.second) < 0; 
	});

	for (pair<int, string> proximo: proximos){
		buscar(proximo.first, proximo.second);
	}
}

int main() {	
	int count = 1;
	while (true) {
		int qtdLetras; cin>>qtdLetras;
		if (qtdLetras == 0) {
			break;
		}

		dicionario.clear();
		traducoes.clear();
		palavra = "";

		for (int i = 0; i < qtdLetras; i++) {
			string traducao, codigo; cin>>traducao>>codigo;
			dicionario[codigo] = traducao;
			if (codigo.size() == 1) dicionario["0"+codigo] = traducao;
		}

		cin>>palavra;

		cout<<"Case #"<<count<<"\n";
		buscar(0, "");
		for (string traducao: traducoes) {
			cout<<traducao<<endl;
		}

		cout<<endl;
		count++;
	}
	return 0;
}