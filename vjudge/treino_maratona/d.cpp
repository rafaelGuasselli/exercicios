#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<int> adjR[100001];
int marked[100001];
int nMafia, nGuesses;

int dfs(int vertice) {
    marked[vertice] = 1;
    int total = 1;
    
    for(int child: adj[vertice]){
        if (!marked[child]) {
            total += dfs(child);
        }
    }
    
    return total;
}

vector<pair<int, int>> order;

void dfsO(int vertice, int depth) {
    if (adjR[vertice].size() == 0) {
        order.push_back({depth, vertice});
    }
    
    for (int child: adjR[vertice]) {
        dfsO(child, depth+1);
    }
}

int main() {
    cin>>nMafia>>nGuesses;
    for (int i = 2; i <= nMafia; i++) {
        int boss; cin>>boss;
        adj[i].push_back(boss);
        adjR[boss].push_back(i);
    }
    
    dfsO(1, 1);
    sort(order.begin(), order.end(), greater<pair<int, int>>());
    
    for (int i = 0; i <= nMafia; i++) {
        marked[i] = 0;
    }
    
    multiset<int, greater<int>> sums;
    for (int i = 0; i < order.size(); i++) {
        int vertice = order[i].second;
        sums.insert(dfs(vertice));
    }
    
    int total = 0;
    int count = 0;
    for (int i: sums) {
        total += i;
        count++;
        if (count==nGuesses) {
            break;
        }
    }
    
    cout<<total<<endl;
    
    return 0;
}