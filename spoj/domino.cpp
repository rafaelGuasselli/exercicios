#include<bits/stdc++.h>
using namespace std;

int matrix[7][8];
int nTests;

map<set<int>, int> ids = {
	{{0, 0}, 1},  {{0, 1}, 2},   {{0, 2}, 3},  {{0, 3}, 4},
	{{0, 4}, 5},  {{0, 5}, 6},   {{0, 6}, 7},  {{1, 1}, 8},
	{{1, 2}, 9},  {{1, 3}, 10},  {{1, 4}, 11}, {{1, 5}, 12},
	{{1, 6}, 13}, {{2, 2}, 14},  {{2, 3}, 15}, {{2, 4}, 16},
	{{2, 5}, 17}, {{2, 6}, 18},  {{3, 3}, 19}, {{3, 4}, 20},
	{{3, 5}, 21}, {{3, 6}, 22},  {{4, 4}, 23}, {{4, 5}, 24},
	{{4, 6}, 25}, {{5, 5}, 26},  {{5, 6}, 27}, {{6, 6}, 28} 
}; 

pair<int, int> nextPos(pair<int, int> pos) {
	int i = pos.first;
	int j = pos.second;
	if (j <= 6) {
		return {i, j+1};
	} else {
		return {i+1, 0};
	}
}

int fill(pair<int, int> pos, char direction, bitset<29> used, vector<bitset<8>> marked) {
	int i = pos.first; int j = pos.second;
	if (i < 0 || j < 0 || i >= 7 || j >= 8) {
		return 0;
	}
	
	int ni, nj;
	if (direction == 'h') {
		ni = 0; nj = 1;
	} else {
		ni = 1; nj = 0;
	}

	int total = 0;
	int notOutOfBounds = (i+ni) < 7 && (j+nj) < 8;
	if (marked[i].test(j)){
		total += fill(nextPos(pos), direction, used, marked);
	} else if (notOutOfBounds) {
		int empty = !marked[i].test(j) && !marked[i+ni].test(j+nj);
		if (empty) {
			set<int> piece = {matrix[i][j], matrix[i+ni][j+nj]};
			int id = ids[piece]; 

			if (id > 0 && !used.test(id)) {
				marked[i].set(j);
				marked[i+ni].set(j+nj);

				used.set(id);
				if (used.count() == 28) {
					return 1;
				}


				total += fill(nextPos(pos), 'h', used, marked);
				total += fill(nextPos(pos), 'v', used, marked);
			}
		} 
	}

	return total;
}

int main() {
	scanf("%d", &nTests);
	for (int t = 0; t < nTests; t++) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		int total = 0;
		total += fill({0, 0}, 'h', {}, {{}, {}, {}, {}, {}, {}, {}});
		total += fill({0, 0}, 'v', {}, {{}, {}, {}, {}, {}, {}, {}});

		printf("Teste %d\n", t+1);
		printf("%d\n", total);
	}
	
	return 0;
}