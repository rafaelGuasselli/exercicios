#include<bits/stdc++.h>

using namespace std;

int matrix[1005][1005];
int nLines, nColuns;

int mod(int n, int m){
	return ((n%m)+m)%m;
}

int main() {
	int nTest = 1;
	while (cin>>nLines>>nColuns) {
		if (nLines == 0 && nColuns == 0) {
			break;
		}

		for (int l = 0; l < nLines; l++) {
			for (int c = 0; c < nColuns; c++) {
				cin>>matrix[l][c];
			}
		}

		int x, y;
		int dx = 0;
		int dy = 0;

		while (cin>>x>>y) {
			if (x == 0 && y == 0) {
				break;
			}

			dx -= x;
			dy += y;
		}
		
		cout<<"Teste "<<nTest++<<endl;
		for (int l = 0; l < nLines; l++) {
			for (int c = 0; c < nColuns; c++) {
				if (c > 0) {
					cout<<" ";
				}

				cout<<matrix[mod(l+dy, nLines)][mod(c+dx, nColuns)];
			}
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}