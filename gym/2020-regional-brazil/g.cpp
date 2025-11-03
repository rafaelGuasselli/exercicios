#include <bits/stdc++.h>

using namespace std;

vector<int> prof;
vector<int> pos;
vector<int> fumo;
vector<int> visited;
int n, k;


void bfs(int startNode) {
    queue<pair<int, int>> q;

    q.push({0, startNode});
	prof[startNode] = 0;

    while (!q.empty()) {
        int u = q.front().second; 
		q.pop();

		if (u == n) {
			break;
		}

        for (int v = n; v > u; v--) {
            if (pos[u] + fumo[u] >= pos[v] && prof[u]+1 < prof[v]) {
				prof[v] = prof[u] + 1;
                q.push({prof[v], v});
            }
        }
    }
}



int main() {
	cin >> n >> k;

	visited.assign(n+1,false);
	prof.assign(n+1, 1000000);

	pos.push_back(0);
	fumo.push_back(k);

	for (int i = 1; i <= n; i++) {
		int p; cin>>p;
		pos.push_back(p);
	}

	for (int i = 1; i <= n; i++) {
		int p; cin>>p;
		fumo.push_back(p);
	}

	bfs(0);

	if (prof[n] == 1000000) {
		cout<<-1<<endl;
	} else {
		cout<<prof[n]-1<<endl;
	}
}