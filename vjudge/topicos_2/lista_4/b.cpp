#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {	
    int qtdLivros;

    while (cin >> qtdLivros) {
        int livroA, livroB;
        int menorDiferenca = 100000;

        set<int> numeros;
        map<int, int> falta;
        for (int i = 0; i < qtdLivros; i++) {
            int novoNumero; cin>>novoNumero;
            numeros.insert(novoNumero);
            falta[novoNumero] = 0;
        }

        int objetivo; cin>>objetivo;
        for (int numero:numeros) {
            falta[objetivo - numero] = numero;
        }

        set<pair<int, pair<int, int>>> solucoes;
        for (int numero:numeros) {
            if (falta[numero]) {
                int diferenca = abs(numero - falta[numero]);
                solucoes.insert(make_pair(diferenca, make_pair(falta[numero], numero)));
            }
        }

        pair<int, int> solucao = (*solucoes.begin()).second;
        cout<<"Peter should buy books whose prices are "<<solucao.first<<" and "<<solucao.second<<".\n\n";
    }

    return 0;
}