#include<bits/stdc++.h>

using namespace std;

set<string> sufix;
set<string> prefix;

int main() {
	int n; cin>>n;
	vector<string> palavras(n);

	for (int i = 0; i < n; i++) {
		cin>>palavras[i];
	}

	for (string cadeia: palavras) {
		int fim = 0;
		for (int i = 0; i <= 10; i++) {
			if (sufix.find(cadeia.substr(0, i)) != sufix.end()) {
				string last = cadeia.substr(i, 10-i);
				if (prefix.find(last) != prefix.end()) {
					fim = 1;
					break;
				}
			}
		}

		if (fim) {
			cout<<cadeia<<endl;
			return 0;
		} else {
			for (int i = 0; i <= 10; i++) {
				prefix.insert(cadeia.substr(0, i));
				sufix.insert(cadeia.substr(i, 10-i));
			}
		}
	}

	cout<<"ok"<<endl;


	return 0;
}