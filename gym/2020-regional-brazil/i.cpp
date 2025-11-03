#include<bits/stdc++.h>


using namespace std;

map<int, int> dict[1000000];
int bin[1000000];

int mod(int n, int m) {
	return (m + (n % m)) % m;
}

int main() {
	int n, m; cin>>n>>m;

	int sum = 0;
	int find = 0;

	for (int i = 0; i < m*n; i++) {
		char character; cin>>character;
		int x = (int)character - 48;
		bin[i] = x;
	}

	for (int i = 0; i < m; i++) {
		sum += bin[n*m-i];
	}

	for (int i = 0; i <= m*n-1; i++) {
		int index = i%(m*n);
		sum = sum + bin[index] - bin[mod(i-m, (m*n))];
		if (dict[index%m][sum]) {
			find = 1;
			break;
		}
		
		dict[index%m][sum] = 1;
	}


	if (!find) {
		cout<<"S"<<endl;
	} else {
		cout<<"N"<<endl;
	}

	return 0;	
}