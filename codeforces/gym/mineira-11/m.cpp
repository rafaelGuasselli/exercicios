#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
#define int long long
using namespace std;




int qtd[200005];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	vector<pair<int, int>> questoes;
	int q, n, maxTime; cin>>q>>n>>maxTime;
	int maxDif = 0;
	
	for (int i = 0; i < q; i++) {
		int d, t; cin>>d>>t;
		questoes.push_back({d, t});
		maxDif = max(maxDif, d);
	}

	sort(questoes.begin(), questoes.end());
	priority_queue<int> heap;
	int requiredTime = 0;

	for (pair<int, int> questao: questoes) {
		if (requiredTime+questao.second <= maxTime) {
			heap.push(questao.second);
			requiredTime += questao.second;
		} else if (heap.size() > 0 && heap.top() > questao.second) {
			requiredTime -= heap.top(); 
			requiredTime += questao.second;

			heap.pop();
			heap.push(questao.second);
		}

		qtd[questao.first] = heap.size();
	}

	int maximo = 0;
	for (int i = 0; i <= maxDif; i++) {
		qtd[i] = maximo = max(qtd[i], maximo);
	}

	for (int i = 0; i < n; i++) {
		int c; cin>>c;
		cout<<qtd[min(c, maxDif)]<<endl;
	}

	return 0;
}