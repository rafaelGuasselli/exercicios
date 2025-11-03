#include<bits/stdc++.h>
#define ll long long

using namespace std;

int amount[2];
int main() {
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;

		char last = -1;
		amount[0] = 0;
		amount[1] = 0;

		for (int i = 0; i < n; i++) {
			char current; cin>>current;
			if (current == '1') {
				amount[1]++;
			} else if (current != last){
				amount[0]++;
			}

			last = current;
		}

		if (amount[1] > amount[0]) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}

    return 0;
}