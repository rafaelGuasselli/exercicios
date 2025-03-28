#include<bits/stdc++.h>
	
using namespace std;
	
const vector<char> vowers = {'a', 'e', 'i', 'o', 'u'};
int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int nChars; cin>>nChars;
		int nRep = nChars/5;
		int sobra = nChars%5;
		string result;
	
		for (int i = 0;  i < 5; i++) {
			int rep = nRep;
			if (sobra > 0) {
				result += vowers[i];
				sobra--;
			}
	
			while (rep) {
				result.push_back(vowers[i]);
				rep--;
			}
		}
	
		cout<<result<<endl;
	}
}