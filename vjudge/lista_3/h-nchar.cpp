#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string, string> dicionario;
map<string, vector<string>> memo;
set<string> buscar(string parteA, string parteB) {
	vector<string> traducoesA;
	if (memo.find(parteA) != memo.end()) {
		traducoesA = memo[parteA];  
	} else {
		for (int i = 0; i < max((int)parteA.size()-1, 0); i++) {
			string a = parteA.substr(0, i+1);
			string b = parteA.substr(i+1, parteA.size()-i);
			set<string> resultado = buscar(a, b);
			traducoesA.insert(traducoesA.end(), resultado.begin(), resultado.end());
		}
	}

	vector<string> traducoesB;
	if (memo.find(parteB) != memo.end()) {
		traducoesB = memo[parteB];  
	} else {
		for (int i = 0; i < max((int)parteB.size()-1, 0); i++) {
			string a = parteB.substr(0, i+1);
			string b = parteB.substr(i+1, parteB.size()-i);

			set<string> resultado = buscar(a, b);
			traducoesB.insert(traducoesB.end(), resultado.begin(), resultado.end());
		}
	}

	if (dicionario.find(parteA) != dicionario.end()) traducoesA.push_back(dicionario[parteA]);
	if (dicionario.find(parteB) != dicionario.end()) traducoesB.push_back(dicionario[parteB]);
	if (parteA.size() == 0) traducoesA.push_back("");
	if (parteB.size() == 0) traducoesB.push_back("");
	set<string> traducoes;
	for (string a: traducoesA) {
		for (string b: traducoesB) {
			if ((a+b).size() == 0) continue;
			traducoes.insert(a+b);
		}
	}

	memo[parteA] = traducoesA;
	memo[parteB] = traducoesB;
	return traducoes;
}

int main() {	
	int count = 1;
	while (true) {
		int qtdLetras; cin>>qtdLetras;
		if (qtdLetras == 0) {
			break;
		}

		for (int i = 0; i < qtdLetras; i++) {
			string traducao, codigo; cin>>traducao>>codigo;
			dicionario[codigo] = traducao;
			dicionario["0"+codigo] = traducao;
		}

		string frase; cin>>frase;

		cout<<"Case #"<<count<<"\n";
		set<string> traducoes = buscar(frase, "");
		for (string traducao: traducoes) {
			cout<<traducao<<endl;
		}

		cout<<endl;
		count++;
	}
	return 0;
}