#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {	
    string candidatos; cin>>candidatos;
    int qtdQueries; cin>>qtdQueries;

    for (int i = 0; i < qtdQueries; i++) {
        string query; cin>>query;
        int index = 0;
        int first = 0;
        int last = -1;

        for(int j = 0; j < candidatos.size(); j++){
            if (candidatos[j] == query[index]) {
                index++;

                if (index == 1) {
                    first = j;
                }

                if (index == query.size()) {
                    last = j;
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