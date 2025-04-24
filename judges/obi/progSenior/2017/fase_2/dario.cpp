#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int winsDario = 0;
	int winsXerxers = 0;

	for (int i = 0; i < n; i++) {
		int d, x; scanf("%d %d", &d, &x);
		if ((d+1)%5 == x || (d+2)%5 == x) {
			winsDario++;
		} else {
			winsXerxers++;
		}
	}

	if (winsDario > winsXerxers) {	
		printf("dario\n");
	} else {
		printf("xerxes\n");
	}

	return 0;
}