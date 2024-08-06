	#include<bits/stdc++.h>
	#define ll long long
	#define MIN(a, b) (a < b) ? a : b
	#define MAX(a, b) (a < b) ? b : a
	#define EPS 1e-9
	#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0

	using namespace std;

	int main() {
		cin.tie(0);
		ios_base::sync_with_stdio(false);

		int n, m; cin>>n>>m;
		vector<int> compra(n);
		vector<int> andares(m);
		
		for (int i = 0; i < n; i++) {
			cin>>compra[i];
		}

		for (int i = 0; i < m; i++) {
			cin>>andares[i];
		}
		
		vector<int> grupo[40];
		int smallest = 1e9;
		for (int i = 0; i < m; i++) {
			smallest = min(smallest, andares[i]);
			int logm = floor(log2(andares[i]));
			for (int j = logm; j < 40; j++) {
				grupo[j].push_back(i);
			}
		}

		string result;
		for (int i = 0; i < n; i++) {
			int logm = floor(log2(compra[i]));
			int index = 0;
			int grupoIndex = 0;

			if (smallest == 1) {
				compra[i] = 0;
				index = m;
			}

			while (grupo[logm].size() <= 0 && logm >= 0) {
				logm--;
			}
			
			while (index < m && logm >= 0) {
				index = grupo[logm][grupoIndex];
				int modulo = andares[index];
				compra[i] %= modulo;
		
				if (compra[i] == 0) {
					break;
				}

				if (floor(log2(compra[i])) < logm || (grupoIndex+1) >= grupo[logm].size()) {
					logm = floor(log2(compra[i]));
					auto it = upper_bound(grupo[logm].begin(), grupo[logm].end(), index);

					while (it == grupo[logm].end()) {
						logm--;
						if (logm < 0) {
							index = m;
							break;
						} else {
							it = upper_bound(grupo[logm].begin(), grupo[logm].end(), index);
						}
					}

					if (index == m) {
						break;
					}

					grupoIndex = it - grupo[logm].begin();
				} else {
					grupoIndex++;
				}
			}

			if(i > 0){
				result += " "+to_string(compra[i]);
			}else {
				result += to_string(compra[i]);
			}
		}


		cout<<result<<endl;

		return 0;
	}