#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
const int MAX_EMPLOYEES = 100000;


struct Node {
    int idade;
    int menorIdade; 
    vector<Node*> patroes;
    vector<Node*> empregados;
};

void dfs(Node* node) {
    node->menorIdade = 101;

    for (Node* patrao : node->patroes) {
        node->menorIdade = min(node->menorIdade, patrao->menorIdade);
    }

    for (Node* empregado : node->empregados) {
        dfs(empregado);
    }
}

void empregar(vector<Node>& empregados, int patrao, int empregado) {
    empregados[empregado - 1].patroes.push_back(&empregados[patrao - 1]);
    empregados[patrao - 1].empregados.push_back(&empregados[empregado - 1]);
}

Node makeNode(int idade) {
    Node node;
    node.idade = idade;
    node.menorIdade = 101;
    return node;
}

int main() {
    int qtdEmpregados, qtdRelacoes, qtdInstrucoes;
    cin >> qtdEmpregados >> qtdRelacoes >> qtdInstrucoes;

    array<int, MAX_EMPLOYEES> idades;
    for (int i = 0; i < qtdEmpregados; i++) {
        int idade;
        cin >> idade;
        idades[i] = idade;
    }

    vector<Node> empregados;
    for (int i = 0; i < qtdEmpregados; i++) {
        empregados.push_back(makeNode(idades[i]));
    }

    int patrao, empregado;
    cin >> patrao >> empregado;
    empregar(empregados, patrao, empregado);

    vector<int> lista;
    for (int i = 0; i < qtdRelacoes - 1; i++) {
        cin >> patrao >> empregado;
        lista.push_back(empregado - 1);
        empregar(empregados, patrao, empregado);
    }

    for (int i = 0; i < qtdEmpregados; i++) {
        if (find(lista.begin(), lista.end(), i) == lista.end()) {
            dfs(&empregados[i]);
        }
    }

    for (int i = 0; i < qtdInstrucoes; i++) {
        string instrucao;
        cin >> instrucao;

        if (instrucao[0] == 'P') {
            int empregado; cin >> empregado;
			if (empregados[empregado - 1].menorIdade == 101) {
				cout<<"*"<<endl;
			} else {
				cout<<empregados[empregado - 1].menorIdade<<endl;
			}
        } else if (instrucao[0] == 'T') {
            int a, b;
            cin >> a >> b;

            swap(empregados[a - 1].idade, empregados[b - 1].idade);
            swap(empregados[a - 1], empregados[b - 1]);
            empregados[a - 1].menorIdade = 101;
            empregados[b - 1].menorIdade = 101;

            if (empregados[b - 1].idade < empregados[b - 1].menorIdade && empregados[a - 1].idade < empregados[b - 1].idade) {
                dfs(&empregados[a - 1]);
                dfs(&empregados[b - 1]);
            }
            if (empregados[a - 1].idade < empregados[a - 1].menorIdade && empregados[b - 1].idade < empregados[a - 1].idade) {
                dfs(&empregados[a - 1]);
                dfs(&empregados[b - 1]);
            }
        }
    }

    return 0;
}