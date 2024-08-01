#include<bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("I=%d J=%d\n", 1+2*i, 15-2*(4-i)-j);
		}
	}

	return 0;
}