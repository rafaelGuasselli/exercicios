#include<bits/stdc++.h>
#define MAX(a, b) (a < b) ? b : a

using namespace std;

int main(){
	vector<string> lines;
	int n; cin>>n;
	int biggest = 0;
	for (int i = 0; i < n; i++) {
		string line; cin>>line;
		lines.push_back(line);
		biggest = MAX(biggest, line.size());
	}

	for (int i = 0; i < biggest; i++) {
		string line = "";
		int currentBig = 0;
		for (int j = 0; j < lines.size(); j++) {
			if (i >= lines[j].size() && i < currentBig) {
				line += "*";
				continue;
			}

			if (i < lines[j].size()) line += lines[j][i];
			currentBig = MAX(currentBig, lines[j].size());
		}

		reverse(line.begin(), line.end());
		cout<<line<<endl;
	}

	return 0;
}