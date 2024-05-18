#include<bits/stdc++.h>
using namespace std;

int main() {
	int nVotes; cin>>nVotes;
	int carlosVotes = 0;
	int win = 1;

	for (int i = 0; i < nVotes; i++) {
		int votes; cin>>votes;
		if (i == 0) {
			carlosVotes = votes;
		}

		if (votes > carlosVotes) {
			win = 0;
		}
	}

	if (win) {
		cout<<"S"<<endl;
	} else {
		cout<<"N"<<endl;
	}

	return 0;
}