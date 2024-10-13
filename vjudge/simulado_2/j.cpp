#include<bits/stdc++.h>

using namespace std;


int matrix[500][500];
int main() {
	int n, k; cin>>n>>k;

	string pal; cin>>pal;
	int menor = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (pal[j] == pal[j+i-1]) {
				
 			}
		}
	}

	cout<<menor<<endl;
	return 0;
}