#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    set<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(10);
	a.insert(12);
	a.insert(20);

	cout<<*a.lower_bound(-12031)<<endl;
	cout<<*prev(a.lower_bound(-12031), 1)<<endl;

	return 0;
}