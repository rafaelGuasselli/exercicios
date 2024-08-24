#include<bits/stdc++.h>

using namespace std;

int l, c; 
char matrix[150][150];

void dfs(int y, int x) {
	vector<pair<int, int>> nextMove = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}};
	
	matrix[y][x] = '.';
	int adjacencies = 0;
	for (pair<int, int> nextPos: nextMove) {
		int ny = nextPos.first; int nx = nextPos.second;
		if (ny < 0 || nx < 0 || ny >= l || nx >= c) {
			continue;
		}

		if (matrix[ny][nx] == 'H') {
			adjacencies++;
			dfs(ny, nx);
		}
	}

	if (adjacencies == 0) {
		printf("%d %d\n", y+1, x+1);
	}
}

int main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			matrix[i][j] = 'a';
		}
	}

	int y = 0; int x = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {

			scanf(" %c", &matrix[i][j]);
			if (matrix[i][j] == 'o') {
				y = i; x = j;
			}
		}
	}

	dfs(y, x);
	return 0;
}