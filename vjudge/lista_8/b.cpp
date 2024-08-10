#include<bits/stdc++.h>
using namespace std;

int tracks[51][51];
int nLines, nColumns; 

void setBlock(int ny, int nx){
	if (ny < 0 || ny >= nLines || nx < 0 || nx >= nColumns) {
		return;
	}

	tracks[ny][nx] = -2;
}

int main() {
	while (1) {
		cin>>nLines>>nColumns;

		if (nLines == 0 && nColumns == 0) {
			break;
		}

		for (int l = 0; l < 51; l++) {
			for (int c = 0; c < 51; c++) {
				tracks[l][c] = -1;
			}
		}

		for (int l = 0; l < nLines; l++) {
			for (int c = 0; c < nColumns; c++) {
				int current; cin>>current;
				if (current) {
					setBlock(l, c);
					setBlock(l+1, c);
					setBlock(l, c+1);
					setBlock(l+1, c+1);
				} 
			}
		}

		int robotY, robotX, destinationY, destinationX; cin>>robotY>>robotX>>destinationY>>destinationX;
		string direction; cin>>direction;

		queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q;
		map<string, pair<int, int>> directions = {{"north", {-1, 0}}, {"south", {1, 0}}, {"west", {0, -1}}, {"east", {0, 1}}};

		q.push({directions[direction], {0, {robotY, robotX}}});
		tracks[robotY][robotX] = 0;

		while (!q.empty()) {
			pair<pair<int, int>, pair<int, pair<int, int>>> current = q.front(); q.pop();
			
			pair<int, int> direction = current.first;
			int dy = direction.first;
			int dx = direction.second;
			int time = current.second.first;
			int y = current.second.second.first;
			int x = current.second.second.second;

			for (auto next: directions) {
				int my = next.second.first;
				int mx = next.second.second;
				
				pair<int, int> nextDirection = next.second; 

				for (int i = 1; i <= 3; i++) {
					int ny = y + my * i;
					int nx = x + mx * i;

					if (ny <= 0 || ny >= nLines || nx <= 0 || nx >= nColumns) {
						continue;
					}

					if (tracks[ny][nx] == -2) {
						break;
					}

					int bestMoveTime = 0;
					if (nextDirection == direction) {
						bestMoveTime = time + 1;
					} else if (my == -dy || mx == -dx) {
						bestMoveTime = time + 3;
					} else {
						bestMoveTime = time + 2;
					}

					if (bestMoveTime < tracks[ny][nx] || tracks[ny][nx] == -1) {
						tracks[ny][nx] = bestMoveTime;
						q.push({nextDirection, {bestMoveTime, {ny, nx}}});
					}
				}
			}
		}

		// for (int l = 0; l < nLines; l++) {
		// 	for (int c = 0; c < nColumns; c++) {
		// 		cout<<setw(2)<<setfill('0');
		// 		if (tracks[l][c] != -2) {
		// 			cout<<tracks[l][c]<<" ";
		// 		} else {
		// 			cout<<"XX ";
		// 		}
		// 	}
			
		// 	cout<<endl;
		// }

		cout<<max(-1, tracks[destinationY][destinationX])<<endl;
	}

	return 0;
}