#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll nCaixas, nPilhas; 
ll pilhas[1050];

int main() {	
	while (scanf("%d %d", &nCaixas, &nPilhas)) {
		if (nCaixas == 0 && nPilhas == 0) {
			break;
		}

		ll x, y; 
		for (int i = 0; i < nPilhas; i++) {
			ll n; scanf("%lld", &n);
			pilhas[i] = n;
			for (int j = 0; j < n; j++) {
				int idCaixa; scanf("%d", &idCaixa);
				if (idCaixa == 1) {
					y = i;
					x = j;
				}
			}
		}
		
		ll left = 0;
		for (int i = 0; i < y; i++) {
			if (pilhas[i] <= x) {
				left = 0;
			} else {
				left += pilhas[i] - x;
			}
		}

		ll right = 0;
		for (int i = nPilhas-1; i > y; i--) {
			if (pilhas[i] <= x) {
				right = 0;
			} else {
				right += pilhas[i] - x;
			}
		}

		ll total = min(left, right) + (pilhas[y] - x - 1);
		printf("%lld\n", total);
	}

	return 0;
}