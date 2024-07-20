#include<bits/stdc++.h>

using namespace std;


vector<int> mk;
vector<int> adj[301];


int residue[301][301];
int p[301];
int nVertices, maxflow;

int hasPath(int from, int to){
	mk.assign(nVertices, 0);

	queue<int> q;
	q.push(from);
	mk[from] = 1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == to) break;

		for (int v: adj[u]) {
			if (residue[v] > 0 && !mk[v]) {
				mk[v] = 1;
				q.push(v);
				p[v] = u;
			}
		}
	}
}

void edmon(int from, int to){
	while (hasPath(from, to)) {
		int bottleNeck = 1e9;
		for (int v = to; v != from; v = p[v]) {
			bottleNeck = min(bottleNeck, residue[p[v]][v]);
		}

		for (int v = to; v != from; v = p[v]) {
			residue[p[v]][v] -= bottleNeck;
			residue[v][p[v]] += bottleNeck;
		}
		
		maxflow += bottleNeck;
	}
}

//0
//290-299 = 0-9
//300 = end;

int main() {
	while (!cin.eof()) {
		string input;
		nVertices = 10;
		maxflow = 0;

		for (int i = 0; i < 300; i++) {
			p[i] = i;
		}

		while (!cin.eof()) {
			getline(cin, input);
			if (input.empty() || input.size() == 0 || input == "") {
				break;
			}

			stringstream inputstream(input);
			char op; string pcs;
			inputstream>>op>>pcs;

			
		}	
	}

    return 0;
}