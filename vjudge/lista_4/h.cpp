	#include <bits/stdc++.h>

	using namespace std;

	int matrix[200][200];
	int qtdLinhas, qtdColunas;

	string b2d(int lStart, int lEnd, int cStart, int cEnd){
		int soma = 0;
		for (int l = lStart; l < lEnd; l++) {
			for (int c = cStart; c < cEnd; c++) {
				soma += matrix[l][c];
			}
		}

		if (soma == 0) {
			return "0";
		} else if (soma == (lEnd-lStart) * (cEnd-cStart)) {
			return "1";
		} else {
			string resultado = "D";
			int lHalf = ceil(lEnd/2);
			int cHalf = ceil(cEnd/2);
			int quadrantes[4][4] = {
				{lStart, lHalf, cStart, cHalf},
				{lStart, lHalf, cHalf,  cEnd},
				{lHalf,  lEnd,  cStart, cHalf},
				{lHalf,  lEnd,  cHalf,  cEnd},
			};

			for (int i = 0; i < 4; i++) {
				resultado += b2d(quadrantes[i][0], quadrantes[i][1], quadrantes[i][2], quadrantes[i][3]);
			}
		}
	}

	int main() {
		
		return 0;
	}