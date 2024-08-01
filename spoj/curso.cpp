#include<bits/stdc++.h>
using namespace std;

int nEdges, nDiciplinas;
vector<vector<int>> adj;
vector<vector<int>> radj;
map<string, int> code;
vector<string> names;
vector<int> visited;

int main() {
	while (1) {
		cin>>nEdges>>nDiciplinas;
		if (nEdges == 0 && nDiciplinas == 0) {
			break;
		}

		adj.clear();
		radj.clear();
		code.clear();
		names.clear();
		visited.clear();

		for (int i = 0; i < nEdges; i++) {
			string disciplina; cin>>disciplina;
			int nConnections; cin>>nConnections;

			if (code.find(disciplina) == code.end()) {
				code[disciplina] = adj.size();
				adj.push_back({}); 
				radj.push_back({}); 
				names.push_back(disciplina);
				visited.push_back(0);
			}

			for (int j = 0; j < nConnections; j++) {
				string dependency; cin>>dependency;

				if (code.find(dependency) == code.end()) {
					code[dependency] = adj.size();
					adj.push_back({}); 
					radj.push_back({}); 
					names.push_back(dependency);
					visited.push_back(0);
				}

				adj[code[disciplina]].push_back(code[dependency]);
				radj[code[dependency]].push_back(code[disciplina]);
			}
		}



		vector<vector<string>> semestres = {{}};
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < adj.size(); i++) {
			if (adj[i].size() == 0) {
				q.push(i);
			}
		}

		int count = 0;
		int semestre = 0;
		while (!q.empty()) {
			int u = q.top(); q.pop();

			semestres[semestre].push_back(names[u]);
			count++;

			if (count == nDiciplinas || q.empty()) {
				semestres.push_back({});
				semestre++;
				count = 0;

				sort(semestres[semestre-1].begin(), semestres[semestre-1].end());
				for (string us: semestres[semestre-1]) {
					int u = code[us];
					visited[u] = 1;
					for (int v: radj[u]) {
						if (visited[v]) continue;
						int valid = 1;
						for (int d: adj[v]) {
							if (!visited[d]) {
								valid = 0;
							}
						}

						if (valid) {
							q.push(v);
						}
					}
				}
			}
		}


		cout<<"Formatura em "<<semestres.size()-1<<" semestres"<<endl;
		for (int i = 0; i < semestres.size()-1; i++) {
			cout<<"Semestre "<<i+1<<" : ";
			for (int j = 0; j < semestres[i].size(); j++) {
				if (j > 0) {
					cout<<" ";
				}

				cout<<semestres[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}