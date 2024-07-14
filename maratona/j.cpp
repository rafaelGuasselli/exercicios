#include <bits/stdc++.h>

using namespace std;

int matrix[5000][5000];

int main() {
	int nLines, nColumns; cin>>nLines>>nColumns;
	int h, v; cin>>h>>v;

	h -= 1;
	v -= 1;

	for (int l = 0; l < nLines; l++) {
		for (int c = 0; c < nColumns; c++) {
			char val; cin>>val;
			if (val == '*') {
				set<pair<int, int>> pos = {{l+h, c+v}, {l+h, c-v}, {l-h, c+v}, {l-h, c-v}, {l+v, c+h}, {l+v, c-h}, {l-v, c+h}, {l-v, c-h}};

				matrix[l][c] = -1;
				for (pair<int, int> p: pos) {
					int y = p.first;
					int x = p.second;
					if (y < 0 || y > nLines || x < 0 || x > nColumns) {
						continue;
					}

					if (matrix[p.first][p.second] != -1) matrix[p.first][p.second]++;
				}
			} 
		}
	}

	int biggest = -1;
	int y = 0;
	int x = 0;
	for (int l = 0; l < nLines; l++) {
		for (int c = 0; c < nColumns; c++) {
			if (matrix[l][c] > biggest) {
				biggest = matrix[l][c];
				y = l;
				x = c;
			}
		}
	}

	cout<<y+1<<" "<<x+1<<endl;
}