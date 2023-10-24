#include<bits/stdc++.h>
using namespace std;

//Todo: Finish.
int calcArv(){
	map<string, double> frequencias;
	map<string, double>::iterator arvore;

	int totalDeArvores = 0;

	while (true) {
		string arvore; 
		getline(cin, arvore);
		if (arvore == "\0") {
			break;
		}

		frequencias[arvore] = (int)frequencias[arvore] + 1;
		totalDeArvores++;
	}

	cout << fixed << setprecision(4);
	for(arvore = frequencias.begin(); arvore != frequencias.end(); arvore++) {
		cout<<arvore->first<<" "<<100.00*arvore->second/totalDeArvores<<endl;
	}

	return 0;
}

int main(){
	int numTestes; cin>>numTestes;
	string empty; 
	cin.get();
	getline(cin, empty);

	for(int i = 0; i < numTestes; i++){
		calcArv();
		cout<<endl;
	}

	return 0;
}