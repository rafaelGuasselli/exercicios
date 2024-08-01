#include<bits/stdc++.h>
using namespace std;

int nEdges, nDiciplinas;
vector<vector<int>> adj;
vector<vector<int>> radj;
map<string, int> code;
vector<string> names;
vector<int> degree;

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
		degree.clear();

		for (int i = 0; i < nEdges; i++) {
			string disciplina; cin>>disciplina;
			int nConnections; cin>>nConnections;

			if (code.find(disciplina) == code.end()) {
				code[disciplina] = adj.size();
				adj.push_back({}); 
				radj.push_back({}); 
				names.push_back(disciplina);
				degree.push_back(0);
			}

			for (int j = 0; j < nConnections; j++) {
				string dependency; cin>>dependency;

				if (code.find(dependency) == code.end()) {
					code[dependency] = adj.size();
					adj.push_back({}); 
					radj.push_back({}); 
					names.push_back(dependency);
					degree.push_back(0);
				}

				int u = code[disciplina];
				int v = code[dependency];

				degree[u]++;
				adj[u].push_back(v);
				radj[v].push_back(u);
			}
		}

		vector<vector<int>> semestres = {{}};
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < adj.size(); i++) {
			if (degree[i] == 0) {
				q.push(i);
			}
		}

		int count = 0;
		int semestre = 0;
		while (!q.empty()) {
			int u = q.top(); q.pop();

			semestres[semestre].push_back(u);
			count++;

			if (count == nDiciplinas || q.empty()) {
				semestres.push_back({});
				semestre++;
				count = 0;
				
				for (int u: semestres[semestre-1]) {
					for (int v: radj[u]) {
						degree[v]--;
						if (degree[v] == 0) {
							q.push(v);
						}
					}
				}
			}
		}

		cout<<"Formatura em "<<semestres.size()-1<<" semestres"<<endl;
		for (int i = 0; i < semestres.size()-1; i++) {
			cout<<"Semestre "<<i+1<<" : ";
			sort(semestres[i].begin(), semestres[i].end(), [](int a, int b){
				return names[a] < names[b];
			});

			for (int j = 0; j < semestres[i].size(); j++) {
				if (j > 0) {
					cout<<" ";
				}

				cout<<names[semestres[i][j]];
			}
			cout<<endl;
		}
	}

	return 0;
}