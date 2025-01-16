#include<bits/stdc++.h>
#define ll long long
 
const ll mod = 1e9+7;
using namespace std;
 
bitset<1000005> prime;
bitset<1000005> dish;
 
ll factor[1000005];
ll potencias[1000001];
ll qtdFatores[1000005];
 
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
 
	return gcd(b, a % b);
}
 
ll mmc(ll a, ll b) {
	return a*b/gcd(a, b);
}
 
int sign(ll val) {
	if (val > 0) {
		return 1;
	} else if (val < 0){
		return -1;
	} else {
		return 0;
	}
}
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
	potencias[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		potencias[i] = (2 * potencias[i-1]) % mod;
	}
 
	dish.reset();
	int nPratos; cin>>nPratos;
	vector<int> pratos;
	for (int i = 0; i < nPratos; i++) {
		int prato; cin>>prato;
		dish.set(prato);
		pratos.push_back(prato);
	}
 
	memset(qtdFatores, 0, sizeof(qtdFatores));
	for (int i = 0; i <= 1000000; i++) {
		factor[i] = i;
	}
 
	prime.set();
 
 
	for (ll i = 2; i <= 1000000; i++) {
		if (prime.test(i)) {			
			for (ll j = i; j <= 1000000; j+=i) {
				prime.reset(j);
				if (dish.test(j)) qtdFatores[i]++;
				factor[j] = i;
			}
		} else {
			for (ll j = i; j <= 1000000; j+=i) {
				prime.reset(j);
				if (dish.test(j)) qtdFatores[i]++;
			}
		}
	}
	
 
	int nAllergies; cin>>nAllergies;
	for (int i = 0; i < nAllergies; i++) {
		int allergy; cin>>allergy;
 
		set<ll> factors;
		ll currentFactor = allergy;
		ll total = 0;
 
		while (currentFactor > 1) {
			factors.insert(factor[currentFactor]);
			currentFactor /= factor[currentFactor];
		}
 
		multiset<ll> inclusionExclusion; 
		for (ll val: factors) {
			multiset<ll> temp;
			for (ll previous: inclusionExclusion) {
				temp.insert(-sign(previous) * mmc(val, abs(previous)));
			}
 
			temp.insert(val);
			for (ll value: temp) {
				inclusionExclusion.insert(value);
			}
		}
 
		for (ll val: inclusionExclusion) {
			total += sign(val) * qtdFatores[abs(val)];
		}	
 
		cout<<potencias[nPratos-total]<<endl;
	} 
 
	return 0;
}