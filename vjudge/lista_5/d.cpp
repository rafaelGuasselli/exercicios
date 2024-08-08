#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {	
    int qtdTestes; cin>>qtdTestes;
    for (int i = 0; i < qtdTestes; i++) {
        int qtdFields; cin>>qtdFields;
		int qtdEspantalhos = 0;
        char fields[100];

        for (int j = 0; j < qtdFields; j++) {
            cin>>fields[j];
        }

		for (int j = 1; j < qtdFields; j++) {
			if(fields[j] == '.' && j + 1 == qtdFields) {
				qtdEspantalhos++;
			} else if (fields[j-1] == '#') {
				continue;
			} else {
				fields[j-1] = '#';
				fields[j] = '#';
				fields[min(j+1, qtdFields-1)] = '#';
				qtdEspantalhos++;
				j++;
			}
		}


        cout<<"Case "<<i+1<<": "<<qtdEspantalhos<<endl;
    }

	return 0;
}