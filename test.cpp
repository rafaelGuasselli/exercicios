#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Time{
	int id, resolvidos, penalidade;
};


int main() {
		set<int> caminhoes;
		caminhoes.insert(2);
		caminhoes.insert(3);
		caminhoes.insert(4);
		caminhoes.insert(5);

		set<int> combinacoes;
		for (auto it = caminhoes.begin(); it != --caminhoes.end(); it) {
			int caminhaoA = *it;
			
			for (auto itb = ++it; itb != caminhoes.end(); ++itb) {
				caminhaoA = caminhaoA*(*itb);
				combinacoes.insert(caminhaoA);
			}
		}

		for (auto c:combinacoes) {
			cout<<c<<endl;
		}

	return 0;
}