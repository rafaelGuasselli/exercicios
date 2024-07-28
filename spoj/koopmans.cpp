#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod(ll n, ll m) {
	return ((n%m)+m)%m;
}

ll mdc(ll a, ll b){
	if (b==0) {
		return a;
	}

	return mdc(b, mod(a, b));
}

ll lcm(ll a, ll b) {
	return a * b / mdc(a, b);
}

ll sumSequence(ll s, ll e) {
	return (s+e) * (e-s+1)/2;
}

int main() {
	ll nTests;
	scanf("%lld", &nTests);
	for (ll t = 0; t < nTests; t++) {
		ll start, end, nNumbers; 
		scanf("%lld %lld %lld\n", &start, &end, &nNumbers);
		
		vector<ll> numbers;		
		vector<ll> inclusionExclusion;
		for (int i = 0; i < nNumbers; i++) {
			ll number; scanf("%lld", &number);
			numbers.push_back(number);
		}

		for (ll number:numbers) {
			int relativelyPrime = 1;
			
			if (number > end) {
				continue;
			} 

			if (relativelyPrime) {
				vector<ll> add;
				for (ll previousNumber: inclusionExclusion) {
					if (abs(lcm(previousNumber, number)) > end) {
						continue;
					}  
					
					add.push_back(-lcm(previousNumber, number));
				}

				for (ll number: add) {
					inclusionExclusion.push_back(number);
				}

				inclusionExclusion.push_back(number);
			}
		}
 
		ll totalSum = 0;
		for (ll number:inclusionExclusion) {
			ll pas = ceil(fabs(double(start)/double(number)));
			ll pae = floor(fabs(double(end)/double(number)));
			totalSum = mod(totalSum, 1300031) + number * sumSequence(pas, pae);
		}

		printf("%lld\n", mod(totalSum, 1300031)); 
	}

	return 0;
}