#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main() {	
	multiset<int> a;

	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(2);
	

	bool b = a.lower_bound(23)==a.end();
	cout<<b<<endl;
	cout<<*a.lower_bound(23)<<endl;

	return 0;
}