#include<bits/stdc++.h>
//#define int long long
using namespace std;

char matrix[1005][1005];
int visited[1005][1005][10];
map<char, pair<int, int>> direct = {{'L', {-1, 0}}, {'R', {1, 0}}, {'D', {0, 1}}, {'U', {0, -1}}};
vector<char> direcoes = {'L', 'D', 'R', 'U'};
int total = 0;
int n, m; 
void dfs(int i, int j, char direction) {
	pair<int, int> move = direct[direction];
	int index = find(direcoes.begin(), direcoes.end(), direction) - direcoes.begin();
	int ni = i + move.second;
	int nj = j + move.first;

	if (!visited[i][j][0]&& !visited[i][j][1]&&!visited[i][j][2]&&!visited[i][j][3]) {
		total++;
	}

	visited[i][j][index] = 1;
	for (int l = 0; l < 4; l++) {
		index = find(direcoes.begin(), direcoes.end(), direction) - direcoes.begin();
		move = direct[direction];
		ni = i + move.second;
		nj = j + move.first;
		
		if (ni < 0 || nj < 0 || ni >= n || j >= m) {
			direction = direcoes[(index+1) % 4];
			continue;
		}

		if (visited[ni][nj][index]) break;
		if (matrix[ni][nj] == '.') {
			dfs(ni, nj, direction);
			break;
		} else {
			direction = direcoes[(index+1) % 4];
		}
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	int posI = 0;
	int posJ = 0;
	char direction = 'L';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>matrix[i][j];

			if (matrix[i][j] != '.' && matrix[i][j] != '#') {
				posI = i;
				posJ = j;
				direction = matrix[i][j];
				matrix[i][j] = '.';
			}
		}
	}

	dfs(posI, posJ, direction);
	cout<<total<<endl;
	return 0;
}