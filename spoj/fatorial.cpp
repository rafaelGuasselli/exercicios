#include<bits/stdc++.h>
using namespace std;

vector<int> f(1000001);

int main() {
	int count = 1;
	long long current = 1;
	for (int i = 1; i <= 1000000; i++) {
		current = current * i;

		while (current > 0 && current % 10 == 0) {
			current /= 10;
		}

		current %= 10000000LL;
		f[i] = current % 10;
	}	


	int n;
	while(scanf("%d ", &n) != EOF) {
		cout<<"Instancia "<<count++<<endl;
		cout<<f[n]<<endl;
	}

	return 0;
}