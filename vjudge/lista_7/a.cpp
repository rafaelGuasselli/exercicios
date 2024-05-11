#include<bits/stdc++.h>

using namespace std;


int matrix[100][100];
int dominator[100][100];
int marked[100];

int nTests;
int nVertices;

string input;


void dfs(int vertice, int blocked){
	if (vertice == blocked) {
		return;
	}

	marked[vertice] = 1;
	if (blocked != -1) {
		dominator[blocked][vertice] = 0;
	}
	
	for (int i = 0; i < nVertices; i++) {
		if (!marked[i] && matrix[vertice][i]) {
			dfs(i, blocked);
		}
	}
}

int main() {
	cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		cin>>nVertices;
		for (int u = 0; u < nVertices; u++) {
			marked[u] = 0;
			for (int v = 0; v < nVertices; v++) {
				cin>>matrix[u][v];
				dominator[u][v] = 0;
			}
		}

		dfs(0, -1);

		for (int i = 0; i < nVertices; i++) {
			if (marked[i]) {
				for (int j = 0; j < nVertices; j++) {
					if (marked[j]) dominator[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < nVertices; j++) {
				marked[j] = 0;
			}

			dfs(0, i);
		}
		
		cout<<"Case "<<t+1<<":\n";
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < 2*nVertices+1; j++) {
				if (j==0) {
					cout<<"+";
				} else if (j < 2*nVertices) {
					cout<<"-";
				} else {
					cout<<"+";
				}
			}
			cout<<"\n";


			for (int j = 0; j < nVertices; j++) {
				if (dominator[i][j]) {
					cout<<"|"<<"Y";
				} else {
					cout<<"|"<<"N";	
				}

				if (j + 1 == nVertices) {
					cout<<"|";
				}
			}
			cout<<"\n";

			if (i + 1 == nVertices) {
				for (int j = 0; j < 2*nVertices+1; j++) {
					if (j==0) {
						cout<<"+";
					} else if (j < 2*nVertices) {
						cout<<"-";
					} else {
						cout<<"+";
					}
				}
				cout<<"\n";
			}
		}

	}

	return 0;
}