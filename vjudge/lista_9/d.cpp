#include<bits/stdc++.h>
#define ll long long

using namespace std;

int nVertices, nEdges;
ll adj[300][300];

int main() {
	cin>>nVertices>>nEdges;

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			adj[i][j] = 1000000000000000000;
		}
	}
	
	

	return 0;
}