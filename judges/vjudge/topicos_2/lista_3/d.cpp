#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int A,B,C;
int ordem[3];

bool teste(int x, int y, int z){
	return x+y+z == A && x*y*z == B && x*x+y*y+z*z == C;
}

int main() {
	int qtdTestes; cin>>qtdTestes;
	for(int i = 0; i < qtdTestes; i++) {
		cin>>A>>B>>C;
		bool possivel = false;	
		
		for (int x = 1; x <= 10000 && !possivel; x++) {
			for (int y = 1; y <= 10000/x && !possivel; y++) {
				if (y == x) continue;
				for (int z = 1; z <= 10000/(x*y) && !possivel; z++) {
					if (z == y || z == x) continue;
					if (teste(x, y, z)) {
						ordem[0] = x; ordem[1] = y; ordem[2] = z;
						possivel = true;
						break;
					}

					if (teste(x, y, -z)) {
						ordem[0] = x; ordem[1] = y; ordem[2] = -z;
						possivel = true;
						break;
					}

					if (teste(x, -y, z)) {
						ordem[0] = x; ordem[1] = -y; ordem[2] = z;
						possivel = true;
						break;
					}

					if (teste(x, -y, -z)) {
						ordem[0] = x; ordem[1] = -y; ordem[2] = -z;
						possivel = true;
						break;
					}

					if (teste(-x, y, z)) {
						ordem[0] = -x; ordem[1] = y; ordem[2] = z;
						possivel = true;
						break;
					}

					if (teste(-x, y, -z)) {
						ordem[0] = -x; ordem[1] = y; ordem[2] = -z;
						possivel = true;
						break;
					}

					if (teste(-x, -y, z)) {
						ordem[0] = -x; ordem[1] = -y; ordem[2] = z;
						possivel = true;
						break;
					}

					if (teste(-x, -y, -z)) {
						ordem[0] = -x; ordem[1] = -y; ordem[2] = -z;
						possivel = true;
						break;
					}
				}
			}
		}

		if (!possivel) {
			cout<<"No solution."<<endl;
		} else {
			sort(ordem, ordem+3);
			cout<<ordem[0]<<" "<<ordem[1]<<" "<<ordem[2]<<endl;
		}
	} 

	return 0;
}