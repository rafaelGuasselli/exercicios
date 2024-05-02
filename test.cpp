#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
	bitset<10> a[10];

	a[2].set(3);
	a[3] = a[2];
	a[3].set(4);

	cout<<a[3].test(3)<<" "<<a[2].test(4)<<endl;

	return 0;
}