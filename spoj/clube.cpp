#include<bits/stdc++.h>
using namespace std;

int largura, altura, larguraDasTabuas, qtdTabuas; 
int possivel(map<int, int> tabuas, int target, double qtdTabuas){
	double achados = 0;
	int tabuasUsadas = 0;
	
	if (tabuas.find(target) != tabuas.end()) {
		achados += min((int)qtdTabuas, tabuas[target]);
		tabuasUsadas +=  min((int)qtdTabuas, tabuas[target]);
		tabuas[target] = 0;
	}

	for (pair<int, int> tabua: tabuas) {
		int tamanho = tabua.first;
		int restantes = tabua.second;

		if (achados == qtdTabuas) {
			return tabuasUsadas;
		}

		if (restantes <= 0) {
			continue;
		}

		if (tabuas.find(target-tamanho) == tabuas.end()) {
			continue;
		}

		if (tabuas[target-tamanho] <= 0) {
			continue;
		}

		if (tamanho == (target-tamanho)) {
			int usados = tabuas[tamanho]/2;
			usados = min((int)qtdTabuas-(int)achados, usados);

			achados += usados;
			tabuasUsadas += 2*usados;
			tabuas[tamanho] -= usados;
			tabuas[target-tamanho] -= usados;
		} else {
			int usados = min(tabuas[tamanho], tabuas[target-tamanho]);
			usados = min((int)qtdTabuas-(int)achados, usados);

			achados += usados;
			tabuasUsadas += 2*usados;
			tabuas[tamanho] -= usados;
			tabuas[target-tamanho] -= usados;
		}
	}

	if (achados == qtdTabuas) {
		return tabuasUsadas;
	} else {
		return 1e9;
	}
}

int main() {
	while (cin>>largura>>altura) {
		if (largura == 0 && altura == 0) {
			break;
		}

		cin>>larguraDasTabuas;
		cin>>qtdTabuas;

		double qtdTabuasLargura = (double)largura*100/larguraDasTabuas;
		double qtdTabuasAltura = (double)altura*100/larguraDasTabuas; 

		map<int, int> tabuas;
		for (int i = 0; i < qtdTabuas; i++) {
			int tabua; cin>>tabua;
			if (tabuas.find(tabua) == tabuas.end()) {
				tabuas[tabua] = 0;
			}

			tabuas[tabua]++;
		}

		int menorQtdTabuas = min(possivel(tabuas, altura, qtdTabuasLargura),  possivel(tabuas, largura, qtdTabuasAltura));
		if (menorQtdTabuas != (int)1e9) {
			cout<<menorQtdTabuas<<endl;
		} else {
			cout<<"impossivel"<<endl;
		}
	}

	return 0;
}