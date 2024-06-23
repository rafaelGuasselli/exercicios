#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<set<int>> adj;

ll nVertices, nEdges, currentOrd, nBridges, biggest, smallest;
int ord[100009];
int low[100009];
int mk[100009];

ll choose(ll n, ll k) {
    if (k == 0) return 1;
    return (n * choose(n - 1, k - 1))/k;
}

void find(int u, int p) {
	ord[u] = low[u] = currentOrd++;

	for (int v: adj[u]) {
		if (p == v) {
			continue;
		}

		if (ord[v] == -1) {
			find(v, u);
		
			if (low[v] > ord[u]) {
				nBridges++;
				ll reachableVertices = currentOrd-ord[v];
				ll maximum = choose(nVertices-reachableVertices, 2) + choose(reachableVertices, 2);
				smallest = min(smallest, maximum);
			}

			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], ord[v]);
		}
	}
}

int main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		cin>>nVertices>>nEdges;
	 
		currentOrd = 0;
		nBridges = 0;
		smallest = 1e18;

		adj.clear();
		adj.assign(nVertices, {});

		for (int i = 0; i < nVertices; i++) {
			ord[i] = -1;
			low[i] = -1;
			mk[i] = 0;
		}

		for (int i = 0; i < nEdges; i++) {
			int a, b; cin>>a>>b;
			int u = min(a, b);
			int v = max(a, b);
			u--;
			v--;

			adj[u].insert(v);
			adj[v].insert(u);
		}

		for (int i = 0; i < nVertices; i++) {
			if (ord[i] == -1) {
				find(i, -1);
			}
		}

		if (nBridges == 0) {
			cout<<choose(nVertices, 2)<<endl;
		} else {
			cout<<smallest<<endl;
		}
	}

	return 0;
}