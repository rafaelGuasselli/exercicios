
#include <bits/stdc++.h>

using namespace std;

int pop[100001];
int nPop, nCompetitors, popPerSec; 

int testar(long long maximo) {
    int qtdCompetidores = 1;
    int soma = 0;
    
    for (int i = 0; i < nPop; i++) {
        soma += pop[i];

		if (pop[i] > maximo) {
			return nCompetitors+1;
		}
        
        if (soma > maximo) {
            soma = pop[i];
            qtdCompetidores++;
        }
        
        if (qtdCompetidores > nCompetitors) {
			return nCompetitors+1;
        }
    }
    
    return qtdCompetidores;
}

int main(){
    cin>>nPop>>nCompetitors>>popPerSec;
    for (int i = 0; i < nPop; i++) {
        cin>>pop[i];
    }
    
    long long start = 0;
    long long end = 10e8;
	int res;
    
    while (start <= end) {
		long long middle = start + (end-start)/2;
        int competidores = testar(middle*popPerSec);
    
        if (competidores <= nCompetitors) {
            end = middle - 1;
			res = middle;
        } else {
            start = middle + 1;
        }
    }
    
    cout<<res<<endl;
    return 0;
}