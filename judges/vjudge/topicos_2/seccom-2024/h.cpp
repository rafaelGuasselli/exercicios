#include<bits/stdc++.h>
#define int long long
using namespace std;

int valores[200010];
int mod(int a, int b) {
	return (((a%b)+b)%b);
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin>>n;
	string s; cin>>s;

	char previous = '.';
	int index = -1;
	int count = 0;
	for (int i = 0; i < n+10; i++) {
		valores[i] = 0;
	}

	s.push_back('.');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != previous) {
			valores[index] = count;
			count = 0;
			index++;
		}

		count++;
		previous = s[i];
	}

	int sum = 0;
	int maior = 0;
	for (int i = 0; i < index; i++) {
		if ((valores[i + 2] + valores[i]) >= valores[(i + 1)]) {
			maior = max(maior, 2 * valores[(i + 1)]);
		}
	}

	for (int i = 0; i < index; i++) {
		int val = min(valores[(i + 1)], valores[i]);
		maior = max(maior, 2*val);
	}

	cout<<maior<<endl;
    return 0;
}