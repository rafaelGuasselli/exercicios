#include<bits/stdc++.h>
using namespace std;

int matrij[10][10];
vector<set<int>> valores = {
	{0, 0}, {0, 1}, {0, 2}, {0, 3},
	{0, 4}, {0, 5}, {0, 6}, {1, 1},
	{1, 2}, {1, 3}, {1, 4}, {1, 5},
	{1, 6}, {2, 2}, {2, 3}, {2, 4},
	{2, 5}, {2, 6}, {3, 3}, {3, 4},
	{3, 5}, {3, 6}, {4, 4}, {4, 5}, 	
	{4, 6}, {5, 5}, {5, 6}, {6, 6},
};

map<set<int>, int> ids = {
	{{0, 0}, 1},  {{0, 1}, 2},   {{0, 2}, 3},  {{0, 3}, 4},
	{{0, 4}, 5},  {{0, 5}, 6},   {{0, 6}, 7},  {{1, 1}, 8},
	{{1, 2}, 9},  {{1, 3}, 10},  {{1, 4}, 11}, {{1, 5}, 12},
	{{1, 6}, 13}, {{2, 2}, 14},  {{2, 3}, 15}, {{2, 4}, 16},
	{{2, 5}, 17}, {{2, 6}, 18},  {{3, 3}, 19}, {{3, 4}, 20},
	{{3, 5}, 21}, {{3, 6}, 22},  {{4, 4}, 23}, {{4, 5}, 24},
	{{4, 6}, 25}, {{5, 5}, 26},  {{5, 6}, 27}, {{6, 6}, 28}
};

bitset<30> used;
bitset<10> marked[10];

int dfs(int y, int x) {
	if (used.count() == 28) {
		return 1;
	}

	int total = 0;
	for (int i = 0; i < 7; i++) {
		int found = 0;
		for (int j = 0; j < 8; j++) {
			set<int> horizontal = {matrij[i][j], matrij[i][j+1]};	
			set<int> vertical = {matrij[i+1][j], matrij[i][j]};
			int w = ids[horizontal];
			int f = ids[vertical];

			if (!used.test(w) && !marked[i].test(j) && !marked[i].test(j+1)) {
				used.set(w);
				marked[i].set(i);
				marked[i].set(j+1);

				total += dfs(i, j);

				used.reset(w);
				marked[i].reset(j);
				marked[i].reset(j+1);
			}
					
			if (!used.test(f) && !marked[i+1].test(j) && !marked[i].test(j)) {
				used.set(f);
				marked[i].set(j);
				marked[i+1].set(j);
				
				total += dfs(i, j);

				used.reset(f);
				marked[i].reset(j);
				marked[i+1].reset(j);
			}
		}
	}
	
	return total;
}

int main() {
	int nTests; scanf("%d", &nTests);
	for (int t = 0; t < nTests; t++) {
		used.reset();
		for (int i = 0; i < 10; i++) {
			marked[i].reset();
			for (int j  = 0; j < 10; j++) {
				matrij[i][j] = -1;
			}
		}

		for (int i = 0; i < 7; i++) {
			for (int j  = 0; j < 8; j++) {
				scanf("%d", &matrij[i][j]);
			}
		}

		int total = dfs(0, 0);
		printf("%d\n", total);
	}

	return 0;
}