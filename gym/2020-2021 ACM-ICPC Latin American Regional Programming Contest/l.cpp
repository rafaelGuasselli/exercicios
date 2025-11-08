#include <bits/stdc++.h>
using namespace std;

int conflitos[500];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, x; cin>>n>>x;
	for (int i = 0; i < n; i++) {
		int s, d; cin>>s>>d;

		for (int j = 0; j <= 480; j++) {
			int sw = max((s-j)/x, 0);
			int ew = ceil((s+d-j)/double(x));

			if (ew < 0) {
				continue;
			}

			while ((j+x*sw) < s) {
				sw++;
			}

			while ((j+x*ew) > (s+d)) {
				ew--;
			}

			if (sw > ew) {
				continue;
			}

			conflitos[j] += (ew-sw+1);
		}
	}

	int menorX = 0;
	for (int i = 0; i <= 480; i++) {
		if (conflitos[i] < conflitos[menorX]) {
			menorX = i;
		}
	}

	cout<<menorX<<" "<<conflitos[menorX]<<endl;
	return 0;
}
