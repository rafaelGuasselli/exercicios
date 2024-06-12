#include<bits/stdc++.h>

using namespace std;

int nVertices;
int matrix[105][105];

int main() {
	cin>>nVertices;

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			cin>>matrix[i][j];
		}
	}

	int valid = 1;
	set<set<int>> remove;
	for (int k = 0; k < nVertices; k++) {
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < nVertices; j++) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					valid = 0;
				}

				if (matrix[i][k] + matrix[k][j] == matrix[i][j] && i != j && k != i && k != j) {
					remove.insert({i, j});
				}
			}
		}
	}


	if (!valid) {
		cout<<"-1"<<endl;
	} else {
		cout<<remove.size()<<endl;
	}

	return 0;
}