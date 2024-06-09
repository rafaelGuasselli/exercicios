#include<bits/stdc++.h>
#define pipic pair<int, pair<int, char>>

using namespace std;

int nEdges;
string from, to, word; 

map<string, int> code;
vector<vector<pipic>> adj;
vector<map<char, int>> distTo;

void addVertice(string name) {
	if (code.find(name) == code.end()) {
		code[name] = adj.size();
		adj.push_back({});
		distTo.push_back({});
	}
}

int main() {
	while (1) {
		cin>>nEdges;
		
		if (nEdges == 0) {
			break;
		}
		
		adj.clear();
		code.clear();
		distTo.clear();

		cin>>from>>to;
		addVertice(from);
		addVertice(to);

		for (int i = 0; i < nEdges; i++) {
			cin>>from>>to>>word;
			addVertice(from);
			addVertice(to);

			int u = code[from];
			int v = code[to];

			adj[u].push_back({(int)word.size(), {v, word[0]}});
			adj[v].push_back({(int)word.size(), {u, word[0]}});

			distTo[u][word[0]] = 100000000;
			distTo[v][word[0]] = 100000000;
		}

		priority_queue<pipic, vector<pipic>, greater<pipic>> q;
		q.push({0, {0, '*'}});
		distTo[0]['*'] = 0;

		while (!q.empty()) {
			pipic current = q.top(); q.pop();
			int dist = current.first;
			int vertice = current.second.first;
			char currentChar = current.second.second;

			if (dist == distTo[vertice][currentChar]) {
				for (pipic edge: adj[vertice]) {
					int weight = edge.first;
					int child = edge.second.first;
					char nextChar = edge.second.second;

					if (currentChar == nextChar) {
						continue;
					}

					if (dist + weight < distTo[child][nextChar]) {
						distTo[child][nextChar] = dist + weight;
						q.push({distTo[child][nextChar], {child, nextChar}});
					}
				}
			}
		}

		int smallestDist = 10000000;
		for (pair<char, int> dist:distTo[1]) {
			smallestDist = min(smallestDist, dist.second);
		}

		if (smallestDist == 10000000) {
			cout<<"impossivel"<<endl;
		} else {
			cout<<smallestDist<<endl;
		}
	}
	return 0;
}