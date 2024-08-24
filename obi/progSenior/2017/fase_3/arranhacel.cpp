#include<bits/stdc++.h>

using namespace std;

int nAndares, nQueries, nSqrt;
int andares[100000] = {0};
int andaresSqrt[320] = {0};

void update(int index, int val) {
	int indexSqrt = index/nSqrt;
	andaresSqrt[indexSqrt] = andaresSqrt[indexSqrt] - andares[index] + val;
	andares[index] = val;
}

int read(int right) {
	int left = 0;
	int total = 0;

	while ((right+1) % nSqrt != 0) {
		total += andares[right--];
	}

	for (int i = 0; i < (right+1)/nSqrt; i++) {
		total += andaresSqrt[i];
	}

	return total;
}

int main() {
	cin>>nAndares>>nQueries;
	nSqrt = ceil(sqrt(nAndares));
	memset(andares, 0, sizeof(andares));
	memset(andaresSqrt, 0, sizeof(andaresSqrt));
	
	for (int i = 0; i < nAndares; i++) {
		int val; cin>>val;
		update(i, val);
	}


	for (int i = 0; i < nQueries; i++) {
		int op; cin>>op;
		if (op == 0) {
			int index, value; cin>>index>>value; 
			update(index-1, value);
		} else {
			int right; cin>>right; 
			cout<<read(right-1)<<endl;
		}
	}

	return 0;
}