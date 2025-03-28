#include<bits/stdc++.h>

using namespace std;

struct Position{
	int y, x;
};

int distTo[11][11];
int matrix[11][11];
int nLines, nColuns, currentDistance;
Position entrada, saida;

void bfs(Position pos){
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			distTo[i][j] = 1e9;
		}
	}

	queue<Position> q; q.push({pos.y, pos.x}); 
	distTo[pos.y][pos.x] = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x; q.pop();
		
		vector<Position> adj = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}};
		for (Position next: adj) {
			if (next.y < 0 || next.x < 0 || next.y >= nLines || next.x >= nColuns) continue;
			if (distTo[y][x]+1 < distTo[next.y][next.x]) {
				distTo[next.y][next.x] = distTo[y][x]+1;

				if (matrix[next.y][next.x] == 0) {
					q.push(next);
				}
			}
		}	
	}
}	

int main(){
	cin>>nLines>>nColuns;
	cin>>entrada.y>>entrada.x; entrada.x--; entrada.y--;
	cin>>saida.y>>saida.x; saida.x--; saida.y--;

	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			if ((i+1) % 2 == 0 && (j+1) % 2 == 0) {
				matrix[i][j] = 1;
			}
		}
	}

	bfs(entrada);
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColuns; j++) {
			cout<<distTo[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}