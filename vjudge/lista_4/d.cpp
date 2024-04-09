#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int p, q, r, s, t, u; 
int crescer = 0;

double testar(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

#define PRECISION 1000000000

double buscar() {
	double inicio = 0;
	double fim = 1;
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
	while (cin>>p>>q>>r>>s>>t>>u) {
		if (testar(1) > testar(0)) {
			crescer = 1;
		}

		double x = buscar();
		if (x != -1) {
			x = round(x * PRECISION)/PRECISION;
			cout<<fixed<<setprecision(4);
			cout<<x<<endl;
		} else {
			cout<<"No solution"<<endl;
		}
	}

	return 0;
}