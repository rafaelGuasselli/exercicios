#include<bits/stdc++.h>
using namespace std;
	
int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, q; cin>>n>>q;
		map<long long, long long> values;
	
	
	
		int anteriorSegments = 0;
		int anterior = 0;
		for (int i = 0; i < n; i++) {
			long long val; cin>>val;
			long long e = i;
			long long d = n - (i+1);
			long long segmentsPonto = e * (d+1) + d;
			long long segmentsSeg = e * (d+1);
	
			values[segmentsPonto] += 1;
			values[segmentsSeg] += max(val - anterior - 1, 0LL); 
			anterior = val;
		}
	
		for (int i = 0; i < q; i++) {
			long long query; cin>>query;
			cout<<values[query]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}