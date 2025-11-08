#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<int> adj[100005];
int aprendivel[100005];
int visited[100005];

vector<int> acumular;

void dfs(int u) {
	visited[u] = 1;
	acumular.push_back(u);
	
	for (int v: adj[u]) {
		if (visited[v]) {
			continue;
		}	

		dfs(v);
	}
}


signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin>>n;
	for (int i = 0; i < n; i++) {
		aprendivel[i] = -1;
		visited[i] = 0;
 	}

	for (int i = 0; i < n; i++) {
		int a, b; cin>>a>>b;
		if (a == 0 && b == 0) {
			aprendivel[i] = 1;
		}

		adj[i].push_back(a-1);
		adj[i].push_back(b-1);
	}

	int count = 0;
	for (int i = 0; i < n;  i++) {
		if (aprendivel[i] != -1) {
			continue;
		}

		for (int j = 0; j < n; j++) {
			visited[j] = 0;
	 	}
 
		
		acumular.clear();
		dfs(i);

		int tValid = 0;
		for (int a: acumular) {
			if (aprendivel[a] == 1) {
				tValid = 1;
			}
		}

		for (int a: acumular) {
			int valid = 1;
			valid &= aprendivel[a];
			for (int v: adj[a]) {
				valid &= visited[v];
			}	
			tValid &= valid;
		}

		if (tValid) {
			count += acumular.size();
		}
	}	

	cout<<count<<endl;

}