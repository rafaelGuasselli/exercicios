#include<bits/stdc++.h>

using namespace std;


int nEdges;
map<string, int> code;
string from, to, word; 
vector<vector<pair<pair<int, char>, pair<int, int>>>> adj;

vector<string> words;
vector<set<char>> charTo;
vector<int> distTo;
vector<map<char, int>> pathFrom;


void addVertice(string name) {
	if (code.find(name) == code.end()) {
		code[name] = words.size();
		words.push_back(name);
		adj.push_back({});
		distTo.push_back(10000000);
		charTo.push_back({});
		pathFrom.push_back({});
	}
}

int dfs(int vertice, char lastChar) {
	if (vertice == 1) {
		pathFrom[vertice][lastChar] = 1;
		return 1;
	}

	if (charTo[vertice].find(lastChar) == charTo[vertice].end()) {
		charTo[vertice].insert(lastChar);

		for (pair<pair<int, char>, pair<int, int>> &edge: adj[vertice]) {
			int valid = edge.first.first;
			char currentChar = edge.first.second; 
			int weight = edge.second.first;
			int to = edge.second.second;
			
			if (!valid && currentChar != lastChar) {
				int validEdge = dfs(to, currentChar);
				pathFrom[vertice][lastChar] = max(pathFrom[vertice][lastChar], validEdge);
				edge.first.first = max(edge.first.first, validEdge);
			}
		}
	}

	return pathFrom[vertice][lastChar];
}

int main() {
	while (1) {
		cin>>nEdges;
		
		if (nEdges == 0) {
			break;
		}
		
		adj.clear();
		code.clear();
		words.clear();
		distTo.clear();
		charTo.clear();
		pathFrom.clear();

		cin>>from>>to;

		addVertice(from);
		addVertice(to);

		for (int i = 0; i < nEdges; i++) {
			cin>>from>>to>>word;
			addVertice(from);
			addVertice(to);

			int u = code[from];
			int v = code[to];

			adj[u].push_back({{0, word[0]}, {(int)word.size(), v}});
			adj[v].push_back({{0, word[0]}, {(int)word.size(), u}});
		}

		priority_queue<pair<pair<int, char>, pair<int, int>>> q;
		dfs(0, ' ');
		q.push({{0, ' '}, {0, 0}});
		distTo[0] = 0;

		while (!q.empty()) {
			auto current = q.top(); q.pop();
			char lastChar = current.first.second;
			int dist = current.second.first;
			int u = current.second.second;

			if (dist == distTo[u]) {
				for (auto child: adj[u]) {
					int valid = child.first.first;
					char currentChar = child.first.second;
					int weight = child.second.first;
					int v = child.second.second;

					if (!pathFrom[v][lastChar]) {
						continue;
					}

					if (dist + weight < distTo[v]) {
						distTo[v] = dist + weight;
						q.push({{0, currentChar}, {distTo[v], v}});
					}
				}
			}
		}

		if (distTo[1] == 10000000) {
			cout<<"impossivel"<<endl;
		} else {
			cout<<distTo[1]<<endl;
		}
	}
	return 0;
}