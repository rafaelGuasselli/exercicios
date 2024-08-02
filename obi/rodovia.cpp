#include<bits/stdc++.h>

using namespace std;

int nVertices, currentOrd, sccCount;
vector<vector<int>> adj;
vector<int> ordem;

vector<int> low;
vector<int> ord;
vector<int> marked;

void tarjan(int vertice) {
    marked[vertice] = 1;
    ord[vertice] = low[vertice] = currentOrd++;
    ordem.push_back(vertice);

    for (int child: adj[vertice]) {
        if (ord[child] == -1) {
            tarjan(child);
        }

        if (marked[child]) {
            low[vertice] = min(low[vertice], low[child]);
        }
    }

    if (low[vertice] == ord[vertice]) {
		sccCount++;
        while (ordem.size() > 0) {
            int child = ordem.back(); ordem.pop_back();
            marked[child] = 0;

            if (child==vertice) {
                break;
            }
        }
    }
}

int main() {
	cin>>nVertices;

	currentOrd = 0;
	sccCount = 0;
	adj.assign(nVertices, {});
	low.assign(nVertices, 0);
	ord.assign(nVertices, -1);
	marked.assign(nVertices, 0);

	for (int i = 0; i < nVertices; i++) {
		int u, v; cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
	}

	for (int i = 0; i < nVertices; i++) {
		if (ord[i] == -1) {
			tarjan(i);
		}
	}

	if (sccCount == 1) {
		cout<<"S"<<endl;
	} else {
		cout<<"N"<<endl;
	}

	return 0;	
}