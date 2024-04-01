#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

map<string, string> dicionario;
set<string> buscar(string parteA, string parteB) {
	vector<string> traducoesA;
	for (int i = 0; i < max((int)parteA.size()-1, 0); i++) {
		string a = parteA.substr(0, i+1);
		string b = parteA.substr(i+1, parteA.size()-i);
		set<string> resultado = buscar(a, b);
		traducoesA.insert(traducoesA.end(), resultado.begin(), resultado.end());
	}

	vector<string> traducoesB;
	for (int i = 0; i < max((int)parteB.size()-1, 0); i++) {
		string a = parteB.substr(0, i+1);
		string b = parteB.substr(i+1, parteB.size()-i);

		set<string> resultado = buscar(a, b);
		traducoesB.insert(traducoesB.end(), resultado.begin(), resultado.end());
	}

	if (dicionario.find(parteA) != dicionario.end()) traducoesA.push_back(dicionario[parteA]);
	else traducoesA.push_back("");
	if (dicionario.find(parteB) != dicionario.end()) traducoesB.push_back(dicionario[parteB]);
	else traducoesB.push_back("");
	set<string> traducoes;
	for (string a: traducoesA) {
		for (string b: traducoesB) {
			if (a+b=="") continue;
			traducoes.insert(a+b);
		}
	}

	return traducoes;
}

int main() {	
	dicionario["12"] = "a";
	dicionario["1"] = "b";
	dicionario["2"] = "c";
	dicionario["3"] = "d";
	dicionario["23"] = "e";

	set<string> traducoes = buscar("123", "");
	for (string traducao: traducoes) {
		cout<<traducao<<endl;
	}

	return 0;
}