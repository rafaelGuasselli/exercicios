#include<bits/stdc++.h>

using namespace std;

int main() {
	int nTests; cin>>nTests; 
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;
		string s; cin>>s;

		map<char, int> count;
		for (int i = 0; i < n; i++) {
			if (count.find(s[i]) == count.end()) {
				count[s[i]] = 0;
			}
			
			count[s[i]]++;
		}

		string result = "";
		result.push_back(s[0]); 
		count[s[0]]--;

		for (int i = 1; i < n; i++) {
			for (pair<char, int> val: count) {
				if (val.second > 0 && result[i-1] != val.first) {
					result.push_back(val.first);
					count[val.first]--;
					if (count[val.first] == 0) {
						count.erase(val.first);
					}
					
					break;
				} 
			}
		}

		for (pair<char, int> val: count) {
			while(count[val.first] > 0) {
				result.push_back(val.first);
				count[val.first]--;
			}
		}

		cout<<result<<endl;
	}

	return 0;
}