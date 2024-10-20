#include<bits/stdc++.h>
//#define int long long
using namespace std;

int totalCartas[200005];
int quantidadeDaCarta[200005];
int startAt[200005];
int cartas[200005];
int cartasDistintas[200005];

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;

		for (int i = 0; i < n; i++) {
			cin>>cartas[i];
		}


		memset(startAt, 0, sizeof(int) * n);
		memset(totalCartas, 0, sizeof(int) * n);
		memset(cartasDistintas, 0, sizeof(int) * n);
		memset(quantidadeDaCarta, 0, sizeof(int) * n);
		sort(cartas, cartas+n);

		int index = -1;
		int anterior = -1;	

		for (int i = 0; i < n; i++) {
			if (anterior != cartas[i]) {
				index++;
				cartasDistintas[index] = cartas[i];
			}

			totalCartas[index]++; 
			quantidadeDaCarta[index]++;
			startAt[index] = index;
			anterior = cartas[i];
		}

		int maximo = 0;
		for (int i = 0; i <= index; i++) {
			if (i-1 >= 0 && cartasDistintas[i] == (cartasDistintas[i-1]+1)) {
				totalCartas[i] = totalCartas[i] + totalCartas[i-1];
				startAt[i] = max(startAt[i-1], i-k);

				if (startAt[i] == i-k && i-k >= 0 && cartasDistintas[i] == (cartasDistintas[i-k]+k)) {
					totalCartas[i] -= quantidadeDaCarta[i-k];
				}
			}

			maximo = max(maximo, totalCartas[i]);
		} 

		cout<<maximo<<endl;
	}

	return 0;
}