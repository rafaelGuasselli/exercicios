#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long

ll values[200000000];

ll mod(ll n, ll m){
    return (m + (n % m)) % m;
}

ll findPissanoPeriody(ll m){
	values[1] = 1;
	values[2] = 1;
	for (int i = 3; i < 200000000; i++) {
		values[i] = mod(values[i-1] + values[i-2], m);
		if (values[i-1] == 0 && values[i] == 1){
			return i;
		}
	} 

	return 1;
}
	
int main(){
	int n, m;
	while(cin>>n>>m){
		int periodo = findPissanoPeriody(m);
		cout<<periodo<<endl;

		ll index = values[n % periodo] % periodo;
		ll fib = values[index] % m;
		cout<<index<<endl;
		cout<<fib<<endl;
	}

	return 0;
}