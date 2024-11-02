#include <iostream>
#include <bits/stdc++.h>
	
using namespace std;
	
	
int main() {	
	int nTests; cin>>nTests;
	
	for (int t = 0; t < nTests; t++) {
		int nBooks; cin>>nBooks;
	
		long long a = 0;
		long long b = 0;
		for (int i = 0; i < nBooks; i++) {
			long long page; cin>>page;
	
			if (i == nBooks-1) {
				b = page;
			} else if (page > a) {
				a = page;
			}
		}
	
		cout<<a+b<<endl;
	}
	
	return 0;
}