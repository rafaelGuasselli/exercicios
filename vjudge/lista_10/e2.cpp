#include<bits/stdc++.h>

using namespace std;

char matrix[31][31];
int residue[2000][2000];
int w, h, p;



vector<int> mk;
vector<int> parent;
vector<int> adj[2000];
int nVertices, s, t, maxflow;



int hasPath(){
	mk.assign(nVertices, 0);
	parent.assign(nVertices, -1);

	queue<int> q;
	q.push(s);
	mk[s] = 1;
	parent[s] = s;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		
		for (int v: adj[u]) {
			if (!mk[v] && residue[u][v] > 0) {
				mk[v] = 1;
				q.push(v);
				parent[v] = u;
			}
		}
	}

	return mk[t];
}

void edmon(){
	maxflow = 0;
	while (hasPath()) {
		int bottleNeck = 1e9;

		for (int v = t; v != s; v = parent[v]) {
			bottleNeck = min(bottleNeck, residue[parent[v]][v]);
		}

		for (int v = t; v != s; v = parent[v]) {
			residue[parent[v]][v] -= bottleNeck;
			residue[v][parent[v]] += bottleNeck;
		}

		maxflow += bottleNeck;
	}
}

int main() {
	while (!cin.eof()) {
		cin>>h>>w>>p;

		if (cin.eof()) {
			break;
		}

		nVertices = w*h+10;
		s = nVertices-1;
		t = nVertices-2;

		for (int i = 0; i < nVertices*2; i++) {
			adj[i].clear();
			for (int j = 0; j < nVertices*2; j++) {
				residue[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin>>matrix[i][j];
				int u = i*w+j;
				if (matrix[i][j] == '#') {
					adj[u].push_back(t);
					residue[u][t] = p;
				} else if(matrix[i][j] == '*') {
					adj[s].push_back(u);
					residue[s][u] = 1;
				}
			}    
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				vector<pair<int, int>> adjency = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
				char current = matrix[i][j];
				int u = i*w + j;

				if (current == '.') {
					adj[u].push_back(nVertices);
					residue[u][nVertices] = 1;
					u = nVertices++;
				}

				for (pair<int, int> element:adjency) {
					int x = element.second;
					int y = element.first;
					int v = y*w+x;

					if (x < 0 || y < 0 || x >= w || y >= h) {
						continue;
					}

					char next = matrix[y][x];
					switch (current) {
						case '*':
							switch (next) {
								case '*':
								case '~':
									residue[u][v] = 0;
									break;								
								case '.':
								case '@':
								case '#':
									adj[u].push_back(v);
									residue[u][v] = 1;
									break;
							}
							break;
						case '~':
							residue[u][v] = 0;
							break;
						case '.':	
							switch (next) {
								case '*':
								case '~':
									residue[u][v] = 0;
									break;								
								case '.':
								case '@':
								case '#':
									adj[u].push_back(v);
									residue[u][v] = 1;
									break;
							}
							break;
						case '@':
						case '#':
							adj[u].push_back(v);
							residue[u][v] = 1e9;
							break;
					}
				}
			}
		}

		edmon();
		cout<<maxflow<<endl;
	}


    return 0;
}