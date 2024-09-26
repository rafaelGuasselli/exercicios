#include<bits/stdc++.h>
#define ll long long

using namespace std;


vector<int> g; 
int total;

void loop(vector<int> numeros, int depth, int target) {
	if (depth == target) {
		vector<int> valores = {0,0,0,0,0};
		int soma = 0;
		for (int a: numeros) {
			valores[a]++;
			soma += a;
		}

		if (soma % 5 != 0) {
			return;
		}

		int minimo = 1e9;
		for (int i = 1; i < 5; i++) {
			if (valores[i] > 0) {
				minimo = min(minimo, g[i]/valores[i]);
			}
		}

		for (int i = 1; i < 5; i++) {
			g[i] -= minimo * valores[i];
		}

		total += minimo;
		return;
	}

	for (int i = 1; i < 5; i++) {
		vector<int> num; num.insert(num.begin(), numeros.begin(), numeros.end());
		num.push_back(i);
		loop(num, depth+1, target);
	}
}

int main() {
    int n; cin>>n;
	g.assign(5, 0);
    for (int i =0; i < n; i++) {
        int a; cin>>a; 
        g[a%5]++;
    }

    total = g[0];
	loop({}, 0, 2);
	loop({}, 0, 3);
	loop({}, 0, 4);
	loop({}, 0, 5);

    cout<<total<<endl;
    return 0;
}