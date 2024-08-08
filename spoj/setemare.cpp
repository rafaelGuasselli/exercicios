#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

pii nextMove(pii enemy, pii player){
	int ey = enemy.first;
	int ex = enemy.second;
	
	int py = player.first;
	int px = player.second;

	if (py > ey) {
		ey += 1;
	} else if (py < ey) {
		ey -= 1;
	}

	if (px > ex) {
		ex += 1;
	} else if (px < ex) {
		ex -= 1;
	}

	return {ey, ex};
}

int compute(vector<vector<char>> state, vector<pii> enemyPos, pii previousPos, pii playerPos, int amountOfEnemies, int amountOfMoves){
	int py = previousPos.first;
	int px = previousPos.second;

	int y = playerPos.first;
	int x = playerPos.second;

	state[py][px] = '.';
	state[y][x] = 'S';

	if (amountOfMoves > 10) {
		return 0;
	}

	for (int i = 0; i < 9; i++) {
		if (enemyPos[i].first == -1) {
			continue;
		}

		pii next = nextMove(enemyPos[i], playerPos);
		state[enemyPos[i].first][enemyPos[i].second] = '.';

		int index = state[next.first][next.second]-'0';
		if (isdigit(state[next.first][next.second]) && i > index) {
			amountOfEnemies -= 2;
			state[next.first][next.second] = '.';
			enemyPos[i] = enemyPos[index] = {-1, -1};
		} else if (state[next.first][next.second] == '#') {
			enemyPos[i] = {-1, -1};
			amountOfEnemies -= 1;
		} else if (state[next.first][next.second] == 'S') {
			return 0;
		} else {
			state[next.first][next.second] = '0'+i;
			enemyPos[i] = next;
		}
	}
	
	if (amountOfEnemies <= 0) {
		return 1;
	}

	vector<pii> nextPlayerMoves = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}, {y+1, x+1}, {y+1, x-1}, {y-1, x+1}, {y-1, x-1}};
	for (pii nextPlayerPos: nextPlayerMoves) {
		int ny = nextPlayerPos.first;
		int nx = nextPlayerPos.second;

		if (ny < 0 || nx < 0 || ny >= 9 || nx >= 8) {
			continue;
		}
		
		if (state[ny][nx] != '.') {
			continue;
		}

		int victory = compute(state, enemyPos, playerPos, nextPlayerPos, amountOfEnemies, amountOfMoves+1);
		if (victory) {
			return 1;
		}
	}

	return 0;
}

int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		vector<vector<char>> state;
		vector<pii> enemyPos;
		pii playerPos;
		int amountOfEnemies = 0;

		state.assign(9, {});
		enemyPos.assign(9, {-1, -1});

		for (int l = 0; l < 9; l++) {
			state[l].assign(8, {});
			for (int c = 0; c < 8; c++) {
				cin>>state[l][c];
				if (state[l][c] == 'E') {
					state[l][c] = '0'+amountOfEnemies;
					enemyPos[amountOfEnemies++] = {l, c};
				} else if(state[l][c] == 'S') {
					playerPos = {l, c};
				}
			}
		}

		int victory = 0;
		int y = playerPos.first;
		int x = playerPos.second;
		vector<pii> nextPlayerMoves = {{y+1, x}, {y, x+1}, {y-1, x}, {y, x-1}, {y+1, x+1}, {y+1, x-1}, {y-1, x+1}, {y-1, x-1}};
		for (pii nextPlayerPos: nextPlayerMoves) {
			int ny = nextPlayerPos.first;
			int nx = nextPlayerPos.second;

			if (ny < 0 || nx < 0 || ny >= 9 || nx >= 8) {
				continue;
			}

			if (state[ny][nx] != '.') {
				continue;
			}

			victory = compute(state, enemyPos, playerPos, nextPlayerPos, amountOfEnemies, 1);

			if (victory) {
				break;;
			}
		}

		if (victory) {
			cout<<"I'm the king of the Seven Seas!"<<endl;
		} else {
			cout<<"Oh no! I'm a dead man!"<<endl;
		}
	}

	return 0;
}