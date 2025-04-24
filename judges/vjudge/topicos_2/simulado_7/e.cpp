#include<bits/stdc++.h>
#define int long long
using namespace std;

bitset<1000006> primo;
int fator[1000006];

void crivo() {
	primo.set();
	for (int i = 2; i < 1000006; i++) {
		if (primo.test(i)) {
			for (int j = 2 * i; j < 1000006; j+= i) {
				primo.reset(i);
				fator[j] = i;
			}
		}
	}
}

int phi(int n) {
	vector<double> p;

	double result = n;
	while (n > 1) {
		p.push_back(fator[n]);
		n /= fator[n];
	}

	for (double primo: p) {
		n *= (1-1/primo);
	}
}


typedef struct {
	int sum, left, right, index, markLeft, markRight;
} Node;

Node* seg[400010];
void update(int index, int left, int right, int value) {
	Node* node = seg[index];
	if (!node->markLeft && left < node->left) {
		update(node->index*2+1, left, min(right, node->right), value);
	} 

	if (!node->markRight && right < node->right) {
		update(node->index*2+1, max(left, node->left), right, value);
	} 

}

int n, q; 
signed main () {
	cin>>n>>q;
	for (int i = 0; i < n; i++) {
		int val; cin>>val;
	}

	for (int i = 0; i < q; i++) {
		int op; cin>>op;
		if (op == 1) {
			int l, r; cin>>l>>r; l--; r--;

		}
	}

	return 0;
}