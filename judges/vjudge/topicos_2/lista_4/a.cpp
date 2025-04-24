#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> pos[1000];
int main() {	
    string candidatos; cin>>candidatos;
    int qtdQueries; cin>>qtdQueries;

	for (int i = 0; i < candidatos.size(); i++) {
		char val = candidatos[i];
		pos[val].push_back(i);
	}

    for (int i = 0; i < qtdQueries; i++) {
        string query; cin>>query;
        int index = -1;
        int first = -1;
        int last = -1;

        for(int j = 0; j < query.size(); j++){
			char q = query[j];
			auto val = upper_bound(pos[q].begin(), pos[q].end(), index); 
			if (val == pos[q].end()) {
				break;
			} else {
				index = *val;
				if (j == 0) {
					first = *val;
				} 

				if (j == query.size()-1) {
					last = *val;
				}
			}	
		}

        if (last != -1) {
            cout<<"Matched "<<first<<" "<<last<<"\n";
        } else{
            cout<<"Not matched"<<endl;
        }
    }

	return 0;
}