#include<bits/stdc++.h>
	
using namespace std;
	
int matrix[300][300];
int visited[300][300];
map<char, pair<int, int>> movimentOp = {{'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, -1}}, {'D', {0, 1}}};
	
int dfs(int i, int j, int pi, int pj) {
	if (matrix[i][j] >= 2) {
		return 1;
	}

	visited[i][j] = 1;
	matrix[i][j]++;

	for (pair<char, pair<int, int>> moVector: movimentOp) {
		int ni = i + moVector.second.first;
		int nj = j + moVector.second.second;
		if (ni < 0 || nj < 0 || ni >= 300 || nj >= 300) {
			continue;
		}

		if (pi == ni && pj == nj) {
			continue;
		}

		if (matrix[ni][nj] > 1) {
			return 1;
		} 
		
		if (!visited[ni][nj] && matrix[ni][nj] > 0) {
			int result = dfs(ni, nj, i, j);
			if (result == 1) {
				return 1;
			}
		} 
	}

	if (matrix[i][j] >= 3) {
		return 1;
	}

	return 0;
}
	
int main(){
	string moviment; cin>>moviment;
	int y = 150;
	int x = 150;
	
	for (char op: moviment) {
		pair<int, int> moveVector = movimentOp[op];
		matrix[x][y]++;
		y += moveVector.second;
		x += moveVector.first;
	}

	matrix[x][y]++;
	if (dfs(150, 150, -1, -1)) {
		cout<<"BUG"<<endl;
	} else {
		cout<<"OK"<<endl;
	}
	
	return 0;
}