#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);  
}

int main() {
	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
	int divisor = lcm(b, d);
	int dividendo = a * divisor/b + c * divisor/d;

	int reduzir = gcd(dividendo, divisor);
	divisor /= reduzir;
	dividendo /= reduzir;
	
	printf("%d %d\n", dividendo, divisor);
	return 0;
}