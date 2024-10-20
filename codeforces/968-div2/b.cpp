#include<bits/stdc++.h>
	
using namespace std;
	
int main() {
	int nTests; cin>>nTests; 
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;
		map<int, int> values;
		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			if (values.find(val) == values.end()) {
				values[val] = 0;
			}
	
			values[val]++;	
		}
	
		for (int i = 0; i < n-1; i++) {
			if (i%2 == 0) {
				map<int, int>::iterator it = values.begin();
				it->second--;
	
				if (it->second == 0) {
					values.erase(it);
				}
			} else {
				map<int, int>::iterator it = --values.end();
				it->second--;
	
				if (it->second == 0) {
					values.erase(it);
				}
			}
		}
	
		map<int, int>::iterator it = values.begin();
		cout<<it->first<<endl;
	}
	
	return 0;
}