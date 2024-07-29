#include<bits/stdc++.h>

using namespace std;

vector<char> sides = {'N', 'L', 'S', 'O'};
map<char, int> sideIndex = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
map<char, pair<int, int>> sidedirection = {{'N', {-1, 0}}, {'L', {0, 1}}, {'S', {1, 0}}, {'O', {0, -1}}};; 

int nLines, nColuns, nInstructions;
char matrix[105][105];

int mod(int n, int m) {
	return ((n%m)+m)%m;
}
int main() {	
	while (cin>>nLines>>nColuns>>nInstructions) {
		if (nLines == 0 && nColuns == 0 && nInstructions == 0) {
			break;
		}

		int py, px;
		for (int l = 0; l < nLines; l++) {
			for (int c = 0; c < nColuns; c++) {
				cin>>matrix[l][c];
				if (isalpha(matrix[l][c])) {
					py = l;
					px = c;
				}
			}
		}

		int figurinhas = 0;
		for (int i = 0; i < nInstructions; i++) {
			char op; cin>>op;
			if (op == 'D') {
				char side = matrix[py][px];
				matrix[py][px] = sides[mod(sideIndex[side]+1, 4)];
			} else if (op == 'E') {
				char side = matrix[py][px];
				matrix[py][px] = sides[mod(sideIndex[side]-1, 4)];
			} else {
				char side = matrix[py][px];
				pair<int, int> direction = sidedirection[side];

				int ny = py + direction.first;
				int nx = px + direction.second;

				if (ny < 0 || nx < 0 || ny >= nLines || nx >= nColuns || matrix[ny][nx] == '#') {
					continue;
				}

				if (matrix[ny][nx] == '*') {
					figurinhas++;
				}

				matrix[ny][nx] = side;
				matrix[py][px] = '.';
			
				px = nx;
				py = ny;
			}
		}

		cout<<figurinhas<<endl;
	}

	return 0;
}