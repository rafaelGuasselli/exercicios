#include<bits/stdc++.h>

using namespace std;

map<char, int> directionIndex = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
vector<pair<int, int>> directionMove = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 

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

		int py, px, direction;
		for (int l = 0; l < nLines; l++) {
			for (int c = 0; c < nColuns; c++) {
				cin>>matrix[l][c];
				if (isalpha(matrix[l][c])) {
					py = l;
					px = c;
					direction = directionIndex[matrix[l][c]];
				}
			}
		}

		int figurinhas = 0;
		for (int i = 0; i < nInstructions; i++) {
			char op; cin>>op;
			if (op == 'D') {
				direction = mod(direction + 1, 4);
			} else if (op == 'E') {
				direction = mod(direction - 1, 4);
			} else {
				pair<int, int> move = directionMove[direction];

				int ny = py + move.first;
				int nx = px + move.second;

				if (ny < 0 || nx < 0 || ny >= nLines || nx >= nColuns || matrix[ny][nx] == '#') {
					continue;
				}

				if (matrix[ny][nx] == '*') {
					figurinhas++;
				}

				matrix[py][px] = '.';
			
				px = nx;
				py = ny;
			}
		}

		cout<<figurinhas<<endl;
	}

	return 0;
}