#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Empregado{
	int idade = 101;
	int menorIdade = 101; 
	vector<Empregado *> patroes;
	vector<Empregado *> empregados;

	Empregado(int idade){
		this->idade = idade;
	}

	void empregar(Empregado* p){
	    this->empregados.push_back(p);
		p->patroes.push_back(this);
	}
};

void dfs(Empregado* node) {
	(*node).menorIdade = 101;

	for (int i = 0; i < (*node).patroes.size(); i++) {
		int menor = min((*(*node).patroes[i]).menorIdade, (*(*node).patroes[i]).idade);
		int menor2 = min((*node).menorIdade, menor);
		(*node).menorIdade = menor2;
	}
	
	for (int i = 0; i < (*node).empregados.size(); i++) {
		dfs((*node).empregados[i]);
	}
}


int ex(int qtdEmpregados, int qtdRelacoes, int qtdInstrucoes){
	int idades[500];
	for (int i = 0; i < qtdEmpregados; i++) {
		int idade; cin >> idade;
		idades[i] = idade;
	}

	vector<Empregado *> empregados;
	for (int i = 0; i < qtdEmpregados; i++) {
		empregados.push_back(new Empregado(idades[i]));
	}

	for (int i = 0; i < qtdRelacoes; i++) {
		int patraoId, empregadoId;
		cin >> patraoId >> empregadoId;
		(*empregados[patraoId-1]).empregar(empregados[empregadoId-1]);
	}

    for (int i = 0; i < qtdEmpregados; i++) {
		if ((*empregados[i]).patroes.size() == 0) {
			dfs(empregados[i]);
		}
    }
	
	for (int i = 0; i < qtdInstrucoes; i++) {
		char instrucao;
		cin >> instrucao;

		if (instrucao == 'P') {
			int indexEmpregado; cin >> indexEmpregado;
			Empregado empregado = *empregados[indexEmpregado - 1];

			if (empregado.menorIdade == 101) {
				cout<<"*"<<endl;
			} else {
				cout<<empregado.menorIdade<<endl;
			}
		} else if (instrucao == 'T') {
			int a, b;
			cin >> a >> b;

			swap((*empregados[a - 1]).idade, (*empregados[b - 1]).idade);	
			swap(empregados[a - 1], empregados[b - 1]);
			(*empregados[a - 1]).menorIdade = 101;
			(*empregados[b - 1]).menorIdade = 101;

			if ((*empregados[b - 1]).idade < (*empregados[b - 1]).menorIdade && (*empregados[a - 1]).idade < (*empregados[b - 1]).idade) {
				dfs(empregados[a - 1]);
				dfs(empregados[b - 1]);
			} else if ((*empregados[a - 1]).idade < (*empregados[a - 1]).menorIdade && (*empregados[b - 1]).idade < (*empregados[a - 1]).idade) {
				dfs(empregados[a - 1]);
				dfs(empregados[b - 1]);
			}

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