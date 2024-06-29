#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int matrix[101][101];
int nLines, nColumns;

int main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		cin>>nLines>>nColumns;

		for (int i = 0; i < nLines; i++) {
			for (int j = 0; j < nColumns; j++) {
				cin>>matrix[i][j];
			}
		}

		int noChanges = 1;
		for (int i = 0; i < nLines; i++) {
			for (int j = 0; j < nColumns; j++) {
				vector<pii> check = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
				set<int> values;
				int current = matrix[i][j];
				int bigger = 1;

				for (pii coordinate: check) {
					int y = coordinate.first;
					int x = coordinate.second;

					if (x < 0 || y < 0 || y >= nLines || x >= nColumns) {
						continue;
					}

					if (current < matrix[y][x]) {
						bigger = 0;
					} else {
						values.insert(matrix[y][x]);
					}
				} 

				if (bigger) {
					matrix[i][j] = *(--values.end());
					noChanges = 0;
				}
			}
		}
		
		for (int i = 0; i < nLines; i++) {
			for (int j = 0; j < nColumns; j++) {
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}