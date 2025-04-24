#include <bits/stdc++.h>

using namespace std;

string bitmapD;
int bitmapB[200][200];
int indice = 0;
int qtdLinhas, qtdColunas;

string b2d(int lStart, int lEnd, int cStart, int cEnd){
	if (lStart >= lEnd || cStart >= cEnd) {
		return "";
	}

	int soma = 0;
	for (int l = lStart; l < lEnd; l++) {
		for (int c = cStart; c < cEnd; c++) {
			soma += bitmapB[l][c];
		}
	}


	if (soma == 0) {
		return "0";
	} else if (soma == (lEnd-lStart) * (cEnd-cStart)) {
		return "1";
	} else {
		string resultado = "D";

		double lHalf = lEnd-lStart;
		double cHalf = cEnd-cStart;
		int vMiddle = lStart+ceil(lHalf/2);
		int hMiddle = cStart+ceil(cHalf/2);

		int quadrantes[4][4] = {
			{lStart, vMiddle, cStart, hMiddle},
			{lStart, vMiddle, hMiddle, cEnd},
			{vMiddle, lEnd, cStart, hMiddle},
			{vMiddle, lEnd, hMiddle, cEnd},
		};

		for (int i = 0; i < 4; i++) {
			resultado += b2d(quadrantes[i][0], quadrantes[i][1], quadrantes[i][2], quadrantes[i][3]);
		}

		return resultado;
	}

	return "";
}

void d2b(int lStart, int lEnd, int cStart, int cEnd){
	if (indice >= bitmapD.size()) {
		return;
	}

	if (lStart >= lEnd || cStart >= cEnd) {
		return;
	}

	

	if (bitmapD[indice] == 'D') {
		double lHalf = lEnd-lStart;
		double cHalf = cEnd-cStart;
		int vMiddle = lStart+ceil(lHalf/2);
		int hMiddle = cStart+ceil(cHalf/2);

		int quadrantes[4][4] = {
			{lStart, vMiddle, cStart, hMiddle},
			{lStart, vMiddle, hMiddle, cEnd},
			{vMiddle, lEnd, cStart, hMiddle},
			{vMiddle, lEnd, hMiddle, cEnd},
		};

		indice++;
		for (int i = 0; i < 4; i++) {
			d2b(quadrantes[i][0], quadrantes[i][1], quadrantes[i][2], quadrantes[i][3]);
		}
	} else {
		int val = bitmapD[indice] - '0';
		indice++;	

		for (int l = lStart; l < lEnd; l++) {
			for (int c = cStart; c < cEnd; c++) {
				bitmapB[l][c] = val;
			}
		}
	}
}

int main() {
	while (true) {
		char tipo; 
		cin>>tipo;

		if (tipo == '#') {
			break;
		}

		indice = 0;
		cin>>qtdLinhas>>qtdColunas;

		int count = 0;
		if (tipo == 'B') {
			for (int l = 0; l < qtdLinhas; l++) {
				for (int c = 0; c < qtdColunas; c++) {
					char value; cin>>value;
					bitmapB[l][c] = value - '0';
				}
			}	

			cout<<setw(0)<<"D";
			cout<<right<<setw(4)<<qtdLinhas;
			cout<<right<<setw(4)<<qtdColunas;
			cout<<endl;

			bitmapD = b2d(0, qtdLinhas, 0, qtdColunas);
			for (int i = 0; i < bitmapD.size(); i++) {
				cout<<bitmapD[i];
				count++;
				if (count == 50 && i + 1 < bitmapD.size()) {
					count = 0;
					cout<<endl;
				}
			}
			
			cout<<endl;
		} else {
			cin>>bitmapD;
			d2b(0, qtdLinhas, 0, qtdColunas);

			cout<<setw(0)<<"B";
			cout<<right<<setw(4)<<qtdLinhas;
			cout<<right<<setw(4)<<qtdColunas;
			cout<<endl;

			for (int l = 0; l < qtdLinhas; l++) {
				for (int c = 0; c < qtdColunas; c++) {
					cout<<bitmapB[l][c];
					count++;
					if (count == 50 && (l + 1 < qtdLinhas || c + 1 < qtdColunas)) {
						count = 0;
						cout<<endl;
					}
				}
			}

			cout<<endl;
		}
	}
	return 0;
}