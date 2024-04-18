#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_FLOR 1000005


ll frequencia[MAX_FLOR];
ll nxt[MAX_FLOR];

ll somarDigitos(ll n) {
    ll soma = 0;
    ll digito = 0;

    while(n >= 1) {    
        digito = n % 10;    
        soma = soma + digito;    
        n = n / 10;    
    }   

    return soma;
}

int main() {	
	int caso = 1;
	while (true) {
		int qtdH, qtdM; cin>>qtdH>>qtdM;

		if (qtdH == 0 && qtdM == 0) {
			break;
		}

		int maisNovo = 1000000;
		for (int i = 0; i < qtdH; i++) {
			int a; cin>>a;
			maisNovo = min(a, maisNovo);
		}

		for (int i = 0; i < qtdM; i++) {
			int a; cin>>a;
		}

		cout<<"Case "<<caso<<": ";
		int sobrando = max(0, qtdH-qtdM);
		if (sobrando != 0) {
			cout<<sobrando<<" "<<maisNovo<<endl;
		} else {
			cout<<'0'<<endl;
		}
		caso++;
	} 

	return 0;
}