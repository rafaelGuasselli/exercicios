#include <bits/stdc++.h>

using namespace std;

int cashflows[11];
int t;
int crescer = 0;

double testar(double irr){
	double npv = 0;
	for (int i = 0; i < t+1; i++) {
		npv += cashflows[i] * pow(1 + irr, t-i);
	}

	return npv;
}

#define PRECISION 100

double buscar() {
	double inicio = -1;
	double fim = 100;
	double meio = 0;

	while (inicio < fim) {
		meio = inicio + (fim-inicio)/2;
		double result = testar(meio);
		result = round(result * PRECISION)/PRECISION;

		if (result == 0){
			return meio;
		} else if (result < 0) {
			if (crescer) {
				inicio = meio;
			} else {
				fim = meio;
			}
		} else {
			if (crescer) {
				fim = meio;
			} else {
				inicio = meio;
			}
		}
	}

	return -1;
}



int main() {	
	while (true) {
		cin>>t;
		if (t == 0) {
			break;
		}

		for (int i = 0; i < t+1; i++) {
			if (testar(10000) > testar(0)) {
				crescer = 1;
			}

			cin>>cashflows[i];
		}

		double result = buscar();
		if (result == -1) {
			cout<<"No"<<endl;
		} else {
			cout<<fixed<<setprecision(2)<<result<<endl;
		}
	}

	return 0;
}