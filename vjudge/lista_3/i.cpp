#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pos[8];
bool testar(){
	set<int> colunas;
	for (int i = 0; i < 8; i++) {
		colunas.insert(pos[i]);
	}

	if (colunas.size() < 8) {
		return false;
	}

	set<int> diagonaisA;
	set<int> diagonaisB;
	for (int l = 0; l < 8; l++) {
		int c = pos[l];
		diagonaisA.insert(l+c);
		diagonaisB.insert((c-l));
	}

	return diagonaisA.size() == 8 && diagonaisB.size() == 8;
}

int main() {	
	for (int i = 0; i < 8; i++) {
		cin>>pos[i];
	}

	return 0;
}