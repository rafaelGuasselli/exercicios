#include<bits/stdc++.h>
#define ll long long

using namespace std;

int sign(ll number) {
	if (number < 0) {
		return -1;
	} else if (number > 0) {
		return 1;
	}

	return 0;
}

ll sumSequence(ll s, ll e) {
	int extra = sign(s);
	return extra * (s+e) * (e-s+extra)/2;
}

int main() {
	printf("%lld\n", sumSequence(-1, -10));
	printf("%lld\n", sumSequence(-4, -10));

	printf("%lld\n", sumSequence(1, 10));
	printf("%lld\n", sumSequence(4, 10));

	printf("%lld\n", sumSequence(-1, 10));
	return 0;
}