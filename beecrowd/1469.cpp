#include<bits/stdc++.h>
using namespace std;

struct Empregado{
	int id;
	int idade = 101;
	vector<Empregado *> patroes;

	Empregado(int id, int idade){
		this->id = id;
		this->idade = idade;
	}

	void empregar(Empregado* p){
		p->patroes.push_back(this);
	}
};

int idades[500];
int visitados[500];

int dfs(Empregado* node, int menorIdade) {
	visitados[(*node).id] = 1;
	for (int i = 0; i < (*node).patroes.size(); i++) {
		Empregado patrao = *(*node).patroes[i];
		if (visitados[patrao.id] == 0) {
			menorIdade = min(patrao.idade, menorIdade);
			menorIdade = min(patrao.idade, dfs(&patrao, menorIdade));
		}
	}

	return menorIdade;
}


int ex(int qtdEmpregados, int qtdRelacoes, int qtdInstrucoes){
	memset(visitados, 0, sizeof visitados);

	for (int i = 0; i < qtdEmpregados; i++) {
		int idade; cin >> idade;
		idades[i] = idade;
	}

	vector<Empregado *> empregados;
	for (int i = 0; i < qtdEmpregados; i++) {
		empregados.push_back(new Empregado(i, idades[i]));
	}

	for (int i = 0; i < qtdRelacoes; i++) {
		int patraoId, empregadoId;
		cin >> patraoId >> empregadoId;
		(*empregados[patraoId-1]).empregar(empregados[empregadoId-1]);
	}
	
	for (int i = 0; i < qtdInstrucoes; i++) {
		char instrucao;
		cin >> instrucao;

		if (instrucao == 'P') {
			int indexEmpregado; cin >> indexEmpregado;
			memset(visitados, 0, sizeof visitados);
			int menorIdade = dfs(empregados[indexEmpregado - 1], 101);

			if (menorIdade == 101) {
				cout<<"*"<<endl;
			} else {
				cout<<menorIdade<<endl;
			}
		} else if (instrucao == 'T') {
			int a, b;
			cin >> a >> b;

			swap((*empregados[a - 1]).idade, (*empregados[b - 1]).idade);	
			swap(empregados[a - 1], empregados[b - 1]);
		}
	}

	return 0;
}

int main(){
	int qtdEmpregados, qtdRelacoes, qtdInstrucoes;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> qtdEmpregados >> qtdRelacoes >> qtdInstrucoes) {
		ex(qtdEmpregados, qtdRelacoes, qtdInstrucoes);
	}

	return 0;
}