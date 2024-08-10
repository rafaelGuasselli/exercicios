#include <iostream>
#define ll long long
using namespace std;

ll fib[1000];
int qtdAs[1000];

int maiorFibPossivel;
bool parar = false;

void buscar(ll atual, int profundidade) {
	if (atual < 1) {
		return;
	}

	if (atual == 1) {
		for (int i = 0; i < profundidade; i++) {
			for (int j = 0; j < qtdAs[i]; j++){
				cout<<"A";
			}
			
			cout<<"B";
		}

		cout<<endl;
		parar = true;
	} else {
		for (int i = maiorFibPossivel; i > 1; i--) {
			if (atual % fib[i] == 0) {
				maiorFibPossivel = i;
				qtdAs[profundidade] = i-1;
				buscar(atual/fib[i], profundidade+1);

				if (parar) {
					return;
				}
			}
		}
	}
}

int main() {	
	ll possibilidades; cin>>possibilidades;
	
	fib[0] = 1;
	fib[1] = 1;
	
	for (int i = 2; i < 1000; i++) {
		fib[i] = fib[i-1] + fib[i-2]; 

		if (fib[i] > possibilidades) {
			maiorFibPossivel = i - 1;
			break;
		}
	}	

	buscar(possibilidades, 0);

	if (!parar) {
		cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}