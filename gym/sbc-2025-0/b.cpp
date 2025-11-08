#include <bits/stdc++.h>
using namespace std;

class OnlineKMP {
public:
	string s;
	int pi[100005];
	int prev[100005][30];

	OnlineKMP() {
		s.clear();
		memset(pi, 0, sizeof(int) * 100005);
		for (int i = 0; i < 100005; i++) {
			memset(prev[i], -1, sizeof(int) * 30);
		}
	}

	void addChar(char c) {
		int newChar = c-'a';
		int old_len = s.size();
		int i = old_len;
		memset(prev[i], -1, sizeof(int) * 30);

		s.push_back(c);
		if (i == 0) {
			return;
		}
		
		int j = nextState(pi[i-1], c);
		if (s[j] == s[i]) {
			j++;
		}

		pi[i] = j;
	}

	void popChar() {
		if (s.empty()) return;
		
		pi[s.size()-1] = 0;
		s.pop_back();
	}

	int nextState(int j, char newChar) {
		int ordChar = newChar-'a';

		if (newChar == s[j]) {
			prev[j][ordChar] = j;
			return prev[j][ordChar];
		}

		if (prev[j][ordChar] != -1) {
			return prev[j][ordChar];
		}

		if (j == 0) {
			prev[j][ordChar] = 0;
		} else {
			prev[j][ordChar] = nextState(pi[j-1], newChar);
		}

		return prev[j][ordChar];
	}

	int smallestPeriod() {
		int len = s.size();
		if (len == 0) return 0;
		int p = pi[len-1];
		int k = len - p;
		int size = 0;
		
		if (k == 0) {
			return len > 2;
		} else {
			if (len%k == 0 && len/k >= 2) {
				return k;
			} else {
				return 0;
			}
		}
	}
};

vector<vector<pair<int, char>>> adj;
OnlineKMP prefixAut;
int maior = 0;



void dfs(int v, int p){
	maior = max(maior, prefixAut.smallestPeriod());
	for(auto e: adj[v]){
		if(e.first == p) continue;
	
		prefixAut.addChar(e.second);
		dfs(e.first, v);
		prefixAut.popChar();
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);


	int n; cin>>n;
	adj.resize(n);
	vector<int> v(n);

	vector<int> P(n);
	for(int i = 0; i<n-1; i++){
		cin>>P[i];
		P[i]--;
	}
	string s_; cin>>s_;
	
	for(int i = 0; i<n-1; i++){
		adj[P[i]].push_back({i+1, s_[i]});
	}

	dfs(0, -1);
	cout<<maior<<endl;
}