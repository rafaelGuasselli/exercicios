#include <bits/stdc++.h>
	
using namespace std;
	
long long calc(double a, double b){
	if (a > b) {
		return 0;
	}
	
	double range = (b - a + 1)/2;
	return (a+b) * range;
}
	
int main() {	
	int nTests; cin>>nTests;
	
	for (int t = 0; t < nTests; t++) {
		long long n, a, b; cin>>n>>a>>b;
		long long k = max(min(b-a, n), 0LL);
	
		if (b > a) {
			cout<<calc(b-k+1, b) + (a * (n-k))<<endl;
		} else {
			cout<<n*a<<endl;
		}
	}
	
	return 0;
}