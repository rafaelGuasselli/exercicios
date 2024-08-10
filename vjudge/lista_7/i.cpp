#include<bits/stdc++.h>

using namespace std;

set<int> adj[100];
set<int> parent[100];

string decode[100];
map<string, int> code;
vector<int> order;

int nVertices, nEdges;
int marked[100];

void bfs() {
	priority_queue<int, vector<int>, greater<int>> queue;
	
	for (int i = 0; i < nVertices; i++) {	
		if (parent[i].size() == 0) {
			queue.push(i);
		}
	}
	
	while (queue.size() > 0) {
		int vertice = queue.top(); queue.pop();

		order.push_back(vertice);
		marked[vertice] = 1;

		for (int child: adj[vertice]) {
			parent[child].erase(vertice);
			if (!marked[child] && parent[child].size() == 0) {
				queue.push(child);
			}
		}
	}
}

int main() {
	int testCase = 1;
	while(cin>>nVertices){
		for (int i = 0; i < nVertices; i++) {
			string drink; cin>>drink;
			code[drink] = i;
			decode[i] = drink;
		}

		order.clear();
		memset(marked, 0, sizeof(int) * nVertices);
		for (int i = 0; i < nVertices; i++) {
			adj[i].clear();
			parent[i].clear();
		}

		cin>>nEdges;
		for (int i = 0; i < nEdges; i++) {
			string from, to; cin>>from>>to;
			adj[code[from]].insert(code[to]);
			parent[code[to]].insert(code[from]);
		}

		bfs();

		cout<<"Case #"<<testCase++<<": Dilbert should drink beverages in this order: ";
		for (int i = 0; i < order.size(); i++) {
			cout<<decode[order[i]];
			if (i + 1 < order.size()) {
				cout<<" ";
			} else {
				cout<<".";
			}
		}

		cout<<"\n\n";
	}

    return 0;
}