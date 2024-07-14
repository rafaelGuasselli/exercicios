#include<bits/stdc++.h>

using namespace std;


struct FlowEdge{
	int u, v;
	int cap, flow;

	FlowEdge(int from, int to, int capacity) {
		u = from;
		v = to;
		cap = capacity;
		flow = 0;
	}

	int other(int vertex) {
		if (vertex == u) return v;
		return u;
	}

	int residualCapacityTo(int vertex) {
		if (vertex == u) return flow;
		return cap - flow;
	}

	void addFlow(int vertex, int f){
		if (vertex == u) {
			flow -= f;
		} else if (vertex == v){
			flow += f;
		}
	}
};


vector<vector<FlowEdge*>> adj;
vector<FlowEdge*> edgeTo;
vector<FlowEdge> edges;

vector<int> op;
vector<int> mk;
int nVertices, maxflow;

int hasPath(int from, int to){
	mk.assign(nVertices, 0);
	edgeTo.assign(nVertices, {});

	queue<int> q;
	
	q.push(from);
	mk[from] = 1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == to) break;

		for (auto &edge: adj[u]) {
			int v = edge->other(u);
			if (edge->residualCapacityTo(v) > 0 && !mk[v]) {
				mk[v] = 1;
				q.push(v);
				edgeTo[v] = edge;
			}
		}
	}
}

void edmon(int from, int to){
	while (hasPath(from, to)) {
		int bottleNeck = 1e9;
		for (int v = to; v != from; v = edgeTo[v]->other(v)) {
			bottleNeck = min(bottleNeck, edgeTo[v]->residualCapacityTo(v));
		}

		for (int v = to; v != from; v = edgeTo[v]->other(v)) {
			edgeTo[v]->addFlow(v, bottleNeck);
		}
		
		maxflow += bottleNeck;
	}
}

int main() {
	string input;
	nVertices = 10;

	adj.assign(nVertices, {});
	maxflow = 0;

	for (int i = 0; i < 10; i++) {
		edges.push_back({i, 10, 1});
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

    return 0;
}