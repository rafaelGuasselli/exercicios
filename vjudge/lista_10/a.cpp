#include<bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
vector<int> p;
vector<int> mk;

int residue[105][105];
int nVertice, nEdges, s, t, maxFlow;

int hasPath(){
    p.clear();
    mk.clear();
    p.assign(nVertice, -1);
    mk.assign(nVertice, 0);

    queue<int> q;
    q.push(s); mk[s] = 1; p[s] = s;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;

        for (int v: adj[u]) {
            if (!mk[v] && residue[u][v] > 0) {
                mk[v] = 1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    return mk[t];
}

int main() {
    int nTest = 1;
    while (1) {
        cin>>nVertice;

        if (nVertice == 0) {
            break;
        }

        cin>>s>>t>>nEdges;
        s--; t--;

        adj.clear();
        adj.assign(nVertice, {});
        maxFlow = 0;
        
        for (int i = 0; i < nVertice; i++) {
            for (int j = 0; j < nVertice; j++) {
                residue[i][j] = 0;
            }
        }

        for (int i = 0; i < nEdges; i++) {
            int u, v, c; cin>>u>>v>>c;
            u--; v--;

            residue[u][v] = residue[u][v] + c;
            residue[v][u] = residue[u][v];

            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        while (hasPath()) {
            int minC = 1e9;
            for (int v = t; v != s; v=p[v]) {
                minC = min(minC, residue[p[v]][v]);
            }

            for (int v = t; v != s; v=p[v]) {
                residue[p[v]][v] -= minC;
                residue[v][p[v]] += minC;
            }

            maxFlow += minC;
        }

        cout<<"Network "<<nTest++<<endl;
        cout<<"The bandwidth is "<<maxFlow<<"."<<endl<<endl;
    }

    return 0;
}