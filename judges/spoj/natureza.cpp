#include<bits/stdc++.h>
using namespace std;

int nVertices, nEdges;
vector<vector<int>> adj;
map<string, int> code;
int biggest;
int visited[5005];


int dfs(int u){
    visited[u] = 1;
    int total = 1;
    for (int v: adj[u]) {
        if (!visited[v]) {
            total += dfs(v);
        }
    }

    return total;
}


int main() {
    while (cin>>nVertices>>nEdges) {
        if (nVertices == 0 && nEdges == 0) {
            break;
        }

        for (int i = 0; i < nVertices; i++) {
            visited[i] = 0;
        }

        biggest = 0;
        adj.clear();
        code.clear();
        for (int i = 0; i < nVertices; i++) {
            string a; cin>>a;
            code[a] = adj.size();
            adj.push_back({});
        }

        for (int i = 0; i < nEdges; i++) {
            string u, v; cin>>u>>v;
            adj[code[u]].push_back(code[v]);
            adj[code[v]].push_back(code[u]);
        }

        for (int i = 0; i < nVertices; i++) {
            if (!visited[i]) {
                biggest = max(biggest, dfs(i));
            }
        }
        
        cout<<biggest<<endl;    
    }

    return 0;
}