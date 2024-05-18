#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll nTests, nVertices, nEdges, currentOrd;

vector<int> adj[100001];
vector<int> parent[100001];
vector<int> ordem;

int low[100001];
int ord[100001];
int marked[100001];

vector<vector<int>> sccs;

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
        sccs.push_back({});
        while (ordem.size() > 0) {
            int child = ordem.back(); ordem.pop_back();
            marked[child] = 0;

            sccs.back().push_back(child);

            if (child==vertice) {
                break;
            }
        }
    }
}

int main() {
    cin>>nTests;
    for (int t = 0; t < nTests; t++) {
        cin>>nVertices>>nEdges;

        currentOrd = 0;
        sccs.clear();
        for (int i = 1; i <= nVertices; i++) {
            adj[i].clear();
            parent[i].clear();
            low[i] = -1;
            ord[i] = -1;
            marked[i] = 0;
        }

        for (int i = 0; i < nEdges; i++) {
            int from, to; cin>>from>>to;
            adj[from].push_back(to);
            parent[to].push_back(from);
        }

        for (int i = 1; i <= nVertices; i++) {
            ordem.clear();
            if (ord[i] == -1) {
                tarjan(i);
            }
        }

        int count = 0;
        for (vector<int> scc: sccs) {
            int dontCount = 0;
            for (int vertice: scc) {
                for (int parent: parent[vertice]) {
                    if (low[vertice] != low[parent]) {
                        dontCount = 1;
                        break;
                    }
                }

                if (dontCount) {
                    break;
                }
            }

            if (!dontCount) {
                count++;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}