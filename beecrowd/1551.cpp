#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int findPissanoPeriody(ll m){
    ll previous = 1;
	ll current = 1;
	int index = 0;
	while (1) {
		ll aux = current;
		current = (current + previous) % m;
		previous = aux;
        if (previous == current && current == 1){
			return index + 1;
		}
		index++;
	}
}

array<ll, 2> fastDoublingFib(ll n, ll m){
    if (n <= 1){
		return array<ll, 2>{1, 1};
	} else{
        array<ll, 2> aux = fastDoublingFib(floor(n / 2), m);
		ll a = aux[1];
		ll b = aux[0];
        ll c = a * ((b << 1) - a);
        ll d = a * a + b * b;

        if (n % 2 == 0){
			return array<ll, 2>{c, d};
		}else{
			return array<ll, 2>{d, (c + d)};
		}
	}
}

void ex(int n, int m){
	int periodo = findPissanoPeriody(m);
	ll v = n % periodo;
    ll fib1 = fastDoublingFib(v, m)[0] % periodo;
    ll fib2 = fastDoublingFib(fib1, m)[0] % periodo;
    cout<<(fib2)<<endl;
}
	
int main(){
	int n, m;
	while(cin>>n>>m){
		ex(n, m);
	}
	return 0;
}