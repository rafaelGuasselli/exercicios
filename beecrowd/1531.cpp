#include<bits/stdc++.h>
using namespace std;
#define ll long long


//C++ permite mod negativo, então por exemplo -9 mod 5 = -4, quando deveria ser 1
//Essa função é um ajuste para compensar isso.
ll mod(ll n, ll m){
    return (m + (n % m)) % m;
}

//Essa função acha o periodo de pissano no fibonacci para um modulo m.
//O periodo de pissano é o tamanho do periodo em que o fibonnacci vai loopar de volta para o inicio.
//A logica do algoritimo é iterar normalmente pelo fibonacci fazendo mod m até encontrar 1 1. 
//A busca termina em 1 1, porque 1 1 é o inicio do fibonacci, então ele vai loopar pelos mesmos valores.
ll findPissanoPeriody(ll m){
    ll previous = 1;
	ll current = 1;
	
    for(ll i = 1; i < m * m; i++) {
		ll aux = current;
		current = (current + previous) % m;
		previous = aux;
        
        if (previous == current && current == 1){
			return i;
		}
    }

    return 0;
}

//Usa multiplicação de matrizes para encontrar fibonacci em O(log n)
//TODO: Pesquisar mais sobre isso, porque eu ainda não entendi como a multiplicação de matrizes funciona.
array<ll, 2> fastDoublingFib(ll n, ll m){
    if (n == 0){
		return array<ll, 2>{0, 1};
	} else{
        array<ll, 2> aux = fastDoublingFib(floor(n / 2), m);
		ll a = aux[0];
		ll b = aux[1];
        ll c = (a * ((b << 1) - a));
        ll d = (a * a + b * b);
        if (n % 2 == 0){
			return array<ll, 2>{mod(c, m), mod(d, m)};
		}else{
			return array<ll, 2>{mod(d, m), mod(c + d, m)};
		}
	}
}

void ex(ll n, ll m){
	int periodo = findPissanoPeriody(m);
    ll fib1 = fastDoublingFib(n, periodo)[0];
    ll fib2 = fastDoublingFib(fib1, m)[0];
    cout<<fib2<<endl;
}
	
int main(){
	ll n, m;
	while(cin>>n>>m){
        ex(n, m);
	}
	return 0;
}