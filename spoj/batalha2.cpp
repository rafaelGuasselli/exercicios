#include<bits/stdc++.h>

using namespace std;


int nLines, nColuwns; 
char matrix[105][105];
int ids[105][105];
int amount[1000000];
int nIds;

int floidFill(int y, int x, int id) {
	vector<pair<int, int>> q = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}};
	int parts = 1;
	ids[y][x] = id;
	
	for (pair<int, int> next: q) {
		if (next.first < 0 || next.second < 0 || next.first >= nLines || next.second >= nColuwns) {
			continue;
		}

		if (matrix[next.first][next.second] == '#' && ids[next.first][next.second] == 0) {
			parts += floidFill(next.first, next.second, id);
		}
	}

	return parts;
}

int main() {
	cin>>nLines>>nColuwns;
	nIds = 1;
	for (int l = 0; l < nLines; l++) {
		for (int c = 0; c < nColuwns; c++) {
			cin>>matrix[l][c];
			ids[l][c] = 0;
		}
	}

	for (int l = 0; l < nLines; l++) {
		for (int c = 0; c < nColuwns; c++) {
			if (matrix[l][c] == '#' && ids[l][c] == 0) {
				int parts = floidFill(l, c, nIds);
				amount[nIds++] = parts;
			}
		}
	}


	int nShots; cin>>nShots; 
	for (int i = 0; i < nShots; i++) {
		int l, c; cin>>l>>c; l--; c--;

		if (matrix[l][c] == '#') {
			amount[ids[l][c]]--;
		}

		matrix[l][c] = 'x';
	}

	int total = 0;
	for (int i = 1; i < nIds; i++) {
		if (amount[i] <= 0) {
			total++;
		}
	}

	cout<<total<<endl;
	cout<<nIds<<endl;
	return 0;
}