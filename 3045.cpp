#include <bits/stdc++.h>

using namespace std;

int matrix[101][101];
vector<pair<int, int>> result2[101][101];

void copyVec(vector<pair<int, int>>& from, vector<pair<int, int>>& to){
	for (pair<int, int> element: from) {
		to.push_back(element);
	}
}

int main() {
	int instancia = 1;
	string a, b; 
	while (cin>>a) {
		if (a == "#") {
			break;
		}

		cin>>b;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				matrix[i][j] = 0;
				result2[i][j].clear();
			}
		}

		for (int i = 1; i <= a.size(); i++) {
			for (int j = 1; j <= b.size(); j++) {
				if (a[i-1] == b[j-1]) {
					matrix[i][j] = matrix[i-1][j-1] + 1;

					copyVec(result2[i-1][j-1], result2[i][j]);
					result2[i][j].push_back({i-1, j-1});
				} else if (matrix[i][j-1] >= matrix[i-1][j]){
					matrix[i][j] = matrix[i][j-1];
					copyVec(result2[i][j-1], result2[i][j]);
				} else {
					matrix[i][j] = matrix[i-1][j];
					copyVec(result2[i-1][j], result2[i][j]);
				}
			}
		}

		
		vector<pair<int, int>> genePos; copyVec(result2[a.size()][b.size()], genePos);
		int am[101], bm[101]; 
		memset(am, 0, sizeof(am));
		memset(bm, 0, sizeof(bm));


		string gene = "";
		string match = "";
		for (int i = 0; i < genePos.size(); i++) {
			am[genePos[i].first] = i+1;
			bm[genePos[i].second] = i+1;
			match += a[genePos[i].first];
		}

		int i = 0;
		int j = 0;
		
		while (i < a.size() || j < b.size()) {
			while (am[i] == 0 && i < a.size()) {
				gene += a[i++];
			}

			while (bm[j] == 0 && j < b.size()) {
				gene += b[j++];
			}

			while (am[i] > 0 && am[i] == bm[j] && i < a.size()) {
				gene += a[i];
				i++; j++;
			}
		}

		cout<<"Teste "<<instancia++<<endl;
		cout<<gene<<endl;
		cout<<endl;
	}

	return 0;
}
