#include<bits/stdc++.h>
#define MAX(a, b) (a < b) ? b : a

using namespace std;

int main(){
	int q; cin>>q;
	unordered_map<int, int> sack;

	for (int i = 0; i < q; i++) {
		int op, value; cin>>op;
		if (op == 1) {
			cin>>value;
			if (sack.find(value) == sack.end()) {
				sack[value] = 0;
			}

			sack[value]++;
		} else if(op == 2){
			cin>>value;
			sack[value] = sack[value]-1;
			if (sack[value] <= 0){
				sack.erase(value);
			} 
		} else {
			cout<<sack.size()<<endl;
		}
	}

	return 0;
}