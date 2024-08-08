#include<bits/stdc++.h>
using namespace std;

bitset<601> ocupados;
int main() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	ocupados.reset();
	for (int i = a; i < a+200; i++) {
		ocupados.set(i);
	}

	for (int i = b; i < b+200; i++) {
		ocupados.set(i);
	}	

	for (int i = c; i < c+200; i++) {
		ocupados.set(i);
	}	

	int area = 0;
	int largura = 0;
	for (int i = 0; i < 600; i++) {
		if (!ocupados.test(i)) {
			largura++;
		} else {
			area += largura * 100;
			largura = 0;
		}
	}

	area += largura * 100;
	printf("%d\n", area);
	return 0;
}