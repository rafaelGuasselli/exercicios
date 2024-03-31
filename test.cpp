#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Time{
	int id, resolvidos, penalidade;
};


int main() {
		set<vector<int>, greater<vector<int>>> conjunto;
		vector<int> a = {1,2,3};
		vector<int> b = {1,2,3};
		vector<int> c = {1,7,8};	
		vector<int> d = {27,7,8};
		vector<int> e = {1,2, 3, 4, 5, 6, 7};

		conjunto.insert(a);
		conjunto.insert(b);
		conjunto.insert(c);
		conjunto.insert(d);
		conjunto.insert(e);
		
		for (vector<int> vetor: conjunto) {
			for (int numero: vetor) {
				cout<<numero<<" ";
			}
			cout<<endl;
		}
	return 0;
}