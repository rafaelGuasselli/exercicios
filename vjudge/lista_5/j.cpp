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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll qtdFlores, gertrudePos; cin>>qtdFlores>>gertrudePos;
	ll maior = 0;
	
    for (ll i = 0; i < qtdFlores; i++) {
        ll flor; cin>>flor;
        frequencia[flor]++;
		maior = max(maior, flor);
    }

	for (ll i = 1; i <= maior; i++) {
		nxt[i] = i - somarDigitos(i);
    }

	for (ll i = maior; i > 0; i--) {
		gertrudePos -= frequencia[i];
		frequencia[nxt[i]] += frequencia[i];

		if (gertrudePos <= 0) {
			cout<<somarDigitos(i)<<endl;
			break;
		}
    }

	if (gertrudePos > 0) {
		cout<<0<<endl;
	}


	return 0;
}