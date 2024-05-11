#include<bits/stdc++.h>

using namespace std;


int matrix[100][100];
int marked[100];
int nVertices;
string input;
int blocked = -1;

void dfs(int vertice){
	marked[vertice] = 1;
	for (int i = 0; i < nVertices; i++) {
		if (i == blocked) {
			continue;
		}

		if (!marked[i] && matrix[vertice][i]) {
			dfs(i);
		}
	}
}

int isCritical(int vertice) {
	if (nVertices<=1) {
		return nVertices;
	}

	for (int l = 0; l < nVertices; l++) {
		marked[l] = 0;
	}

	blocked = vertice;
	dfs((vertice+1)%nVertices);

	for (int i = 0; i < nVertices; i++) {
		if (i == blocked) {
			continue;
		}

		if (marked[i] == 0) {
			return 1;
		}
	}

	return 0;
}

int main() {
	while (true) {
		getline(cin, input);
		stringstream parse(input);
		parse>>nVertices;
		if (nVertices == 0) {
			break;
		}

		for (int l = 0; l < nVertices; l++) {
			marked[l] = 0;
			for (int c = 0; c < nVertices; c++) {
				matrix[l][c] = 0;
			}
		}

		while (true) {
			getline(cin, input);
			stringstream parse(input);

			int from; parse>>from;
			if (from == 0) {
				break;
			}

			int to;
			while (parse>>to) {
				matrix[from-1][to-1] = 1;
				matrix[to-1][from-1] = 1;
			}
		}

		int nCritical = 0;
		for (int i = 0; i < nVertices; i++) {
			if (isCritical(i)) {
				nCritical += 1;
			}
		}
		
		cout<<nCritical<<endl;
	}

    return 0;
}