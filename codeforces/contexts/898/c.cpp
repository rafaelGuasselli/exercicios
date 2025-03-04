#include<bits/stdc++.h>
using namespace std;

int pontos[10][10];
int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				pontos[i][j] = (min(i, j) + 1) % 5;
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout<<pontos[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}