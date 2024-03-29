#include <iostream>
#include <bits/stdc++.h>

using namespace std;


long long factorial(int a){
	long long totalPossibilidades = 1;
	for (int i = 2; i <= a; i++) {
		totalPossibilidades *= i;
	}

	return totalPossibilidades;
}

int main() {
	while(true) {
		int qtdCadeiras, qtdRestricoes; cin>>qtdCadeiras>>qtdRestricoes;

		if (qtdCadeiras == qtdRestricoes && qtdRestricoes == 0) {
			break;
		}


		long long totalPossibilidades = factorial(qtdCadeiras);


		for (int i = 0; i < qtdRestricoes; i++) {
			int a, b, c; cin>>a>>b>>c;

			for (int j = 1; j <= abs(c); j++) {
				totalPossibilidades /= factorial(qtdCadeiras-j);
			}
		}

		cout<<totalPossibilidades<<endl;
	}

	return 0;
}