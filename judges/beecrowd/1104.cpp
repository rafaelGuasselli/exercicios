#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m; 
	while(scanf("%d %d", &n, &m) != EOF) {	
		if (n == 0 && m == 0) {
			break;
		}
		
		bitset<100005> a;
		int totalA = 0;
		for (int i = 0; i < n; i++) {
			int value; scanf("%d", &value);
			if (!a.test(value)) {
				a.set(value);
			}
		}

		bitset<100005> b;
		int totalB = 0;
		for (int i = 0; i < m; i++) {
			int value; scanf("%d", &value);
			if (!b.test(value)) {
				b.set(value);
			}
		}


		for (int i = 0; i < 100005; i++) {
			if (a.test(i) && !b.test(i)) {
				totalA++;
			} else if (!a.test(i) && b.test(i)) {
				totalB++;
			}
		}


		printf("%d\n", min(totalA, totalB));
		
	}
	return 0;
}