#include<bits/stdc++.h>
#define pipic pair<int, pair<int, char>>

using namespace std;

map<char, int> notas = {{'A', 0}, {'B', 2}, {'C', 3}, {'D', 5}, {'E', 7}, {'F', 8}, {'G', 10}};
map<char, int> modificadores = {{'#', 1}, {'b', -1}};
int totalDeNotas = 12;
int nNotas, nTrecho;

int mod(int n, int m) {
	return ((n%m)+m)%m;
}

int main() {
	while (scanf("%d %d\n", &nNotas, &nTrecho)) {
		if (nNotas == 0 && nTrecho == 0) {
			break;
		}

		vector<int> song, trecho;
		int previous = 0;
		for (int i = 0; i < nNotas; i++) {
			char nota[2]; scanf("%s", &nota[0]);
			int val = notas[nota[0]];

			if (modificadores.find(nota[1]) != modificadores.end()) {
				val += modificadores[nota[1]];
			}

			if (i > 0) song.push_back(mod(previous-val, totalDeNotas));
			previous = val;
		}

		previous = 0;
		for (int i = 0; i < nTrecho; i++) {
			char nota[2]; scanf("%s", &nota[0]);
			int val = notas[nota[0]];

			if (modificadores.find(nota[1]) != modificadores.end()) {
				val += modificadores[nota[1]];
			}
			
			if (i > 0) trecho.push_back(mod(previous-val, totalDeNotas));
			previous = val;
		}


		vector<int> lps(trecho.size());
		int len = 0; 
		lps[0] = 0;
		for (int i = 1; i < trecho.size(); i++) {
			if (trecho[i] == trecho[len]) {
				lps[i] = ++len;
			} else if (len > 0) {
				len = lps[len-1];
				i--;
			} else {
				lps[i] = 0;
			}
		}

		int i = 0;
		int j = 0;
		int achou = 0;
		while (i < song.size()) {
			if (song[i] == trecho[j]) {
				i++; j++;
			} else if (j > 0) {
				j = lps[j-1];
			} else {
				i++;
			}

			if (j == trecho.size()) {
				achou = 1;
				break;
			}
		}

		if (achou) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}

	return 0;
}