#include<bits/stdc++.h>
//#define int long long
using namespace std;
 
vector<int> adj[500001];
int nextNode[500001];
int height[500001];
int votes[500001];
 
int buildNextTree(int u, int p) {
	for (int v: adj[u]) {
		if (v == p) continue;
		int depth = buildNextTree(v, u);
		if (depth > height[u]) {
			height[u] = depth;
			nextNode[u] = v;
		}
	}
 
	return height[u]+1;
}
 
void buildVotes(int u, int p, int depth, int acc) {
	votes[depth] += acc;
 
	for (int v: adj[u]) {
		if (v == p) continue;  
		if (v == nextNode[u]) {		
			buildVotes(v, u, depth+1, acc+1);
		} else {
			buildVotes(v, u, depth+1, 1);
		}
	}
}
 
 
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
 
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			votes[i] = 0;
			nextNode[i] = -1;
			height[i] = 0;
		}
 
		for (int i = 0; i < n-1; i++) {
			int u, v; cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
 
		buildNextTree(0, -1);
		buildVotes(0, -1, 0, 1);
 
		int layer = -1;
		int mostVotes = 0;
		for (int i = 0; i < n; i++) {
			if (votes[i] > mostVotes) {
				mostVotes = votes[i];
				layer = i;
			}
		}
 
		cout<<n-mostVotes<<endl;
	}
 
	return 0;
}