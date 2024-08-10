#include<bits/stdc++.h>
using namespace std;

int main() {
	int count = 1;
	while (!cin.eof()) {
		string n; cin>>n;

		if (cin.eof() && n.empty()) {
			break;
		}

		unsigned long long total = 0;
		for (int i = 0; i < n.size(); i++) {
			char a = n[i];
			if (a == 'b') {
				total += (unsigned long long)1<<(n.size()-i-1);
			}
		}

		cout<<"Palavra "<<count++<<endl;
		cout<<total<<endl;
		cout<<endl;
	}


	return 0;
}