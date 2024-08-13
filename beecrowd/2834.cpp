#include<bits/stdc++.h>
using namespace std;

int nLines, nColuns; 
int distTo[11][11];
int sY, sX, eY, eX;
char matrix[11][11];

void bfs(int y, int x){
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			distTo[i][j] = 1e9;
		}
	}	

	queue<pair<int, int>> q; q.push({y, x});
	distTo[y][x] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second; q.pop();
		int d = distTo[y][x];

		vector<pair<int, int>> nexts = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}};
		for (pair<int, int> next: nexts) {
			int ny = next.first;
			int nx = next.second;
			if (ny < 0 || nx < 0 || ny >= nLines || nx >= nColuns) {
				continue;
			}

			if (matrix[ny][nx] == '#') {
				continue;
			}

			if (d+1 < distTo[ny][nx]) {
				distTo[ny][nx] = d+1;
				q.push({ny, nx});
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>nLines>>nColuns;
	cin>>sY>>sX>>eY>>eX; sY--; sX--; eY--; eX--;

	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			if (i % 2 && j % 2) {
				matrix[i][j] = '#';
			} else if (sY == i && sX == j) {
				matrix[i][j] = 'S';
			} else if (eY == i && eX == j) {
				matrix[i][j] = 'E';
			} else {
				matrix[i][j] = '.';
			}
		}
	}

	bfs(sY, sX);
	vector<pair<int, pair<int, int>>> caixas;
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			if (i%2&&j%2) {
				caixas.push_back({distTo[i][j], {i, j}});
			}
		}
	}

	sort(caixas.begin(), caixas.end());

	
	for (pair<int, pair<int, int>> caixa: caixas) {
		int i = caixa.second.first;
		int j = caixa.second.second;
		
		vector<pair<int, int>> nexts = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
		int menor = 1e9;
		int mx = -1;
		int my = -1;
		for (pair<int, int> next: nexts) {
			int ny = next.first;
			int nx = next.second;
			if (ny < 0 || nx < 0 || ny >= nLines || nx >= nColuns) {
				continue;
			}

			if (matrix[ny][nx] == '#') {
				continue;
			}

			bfs(sY, sX);
			if (distTo[eY][eX] < menor) {
				menor = distTo[eY][eX];
				mx = nx; my = ny;
			}
		}

		matrix[my][mx] = '#';
	}
	

	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<distTo[eY][eX]<<endl;
	return 0;
}