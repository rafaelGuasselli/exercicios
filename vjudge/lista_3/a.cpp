#include <bits/stdc++.h>

using namespace std;
int main() {
    vector<pair<int, int>> solucoes[80];
    vector<int> permutacaoAtual = {0,1,2,3,4,5,6,7,8,9};

    do{
        int numerador = 10000 * permutacaoAtual[0];
        numerador += 1000 * permutacaoAtual[1];
        numerador += 100 * permutacaoAtual[2];
        numerador += 10 * permutacaoAtual[3];
        numerador += 1 * permutacaoAtual[4];

        int divisor = 10000 * permutacaoAtual[5];
        divisor += 1000 * permutacaoAtual[6];
        divisor += 100 * permutacaoAtual[7];
        divisor += 10 * permutacaoAtual[8];
        divisor += 1 * permutacaoAtual[9];

        if (numerador % divisor != 0 || numerador < divisor) {
            continue;
        }

        int resultado = (numerador/divisor);
        if (resultado >= 2 && resultado <= 79) {
            solucoes[resultado].push_back(make_pair(numerador, divisor));
        }
    }while(next_permutation(permutacaoAtual.begin(), permutacaoAtual.end()));

    int count = 0;
    while(true) {
        int n; cin>>n;
        if (n == 0) {
            break;
        }

        if (count > 0) {
            printf("\n");
        }

        if (solucoes[n].size() == 0) {
            printf("There are no solutions for %d.\n", n);
            continue;
        }

        for (auto par:solucoes[n]) {
            printf("%05d / %05d = %d\n", par.first, par.second, n);
        }

        count++;
    } 

    return 0;
}