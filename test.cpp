#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Time{
	int id, resolvidos, penalidade;
};


int main() {
	while(true){
		string line;
		if (!getline(cin, line)) {
			break;
		}

		if (line == "" || line == "\0") {
			break;
		}

		cout<<line<<endl;
	}


	return 0;
}