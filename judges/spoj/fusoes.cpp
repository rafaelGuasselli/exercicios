#include<bits/stdc++.h>

using namespace std;

int nBancos, nOp;
int parent[100001];
int amount[100001];
int find(int u){
	if (parent[u] == u) {	
		return u;
	}

	parent[u] = find(parent[u]);
	return parent[u];
}

void join(int u, int v){
	u = find(u);
	v = find(v);
	if (u == v) {
		return;
	}

	if (amount[u] > amount[v]) {
		parent[v] = u;
		amount[u] += amount[v];
	} else {
		parent[u] = v;
		amount[v] += amount[u];
	}
}

int main() {
	cin>>nBancos>>nOp;

	for (int i = 0; i < nBancos; i++) {
		parent[i] = i;
		amount[i] = 1;
	}

	for (int i = 0; i < nOp; i++) {
		char op; int u, v; cin>>op>>u>>v; u--; v--;
		if (op == 'F') {
			join(u, v);
		} else {
			if (find(u) == find(v)) {
				cout<<"S"<<endl;
			} else {
				cout<<"N"<<endl;
			}
		}
	}

	return 0;
}