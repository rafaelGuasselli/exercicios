#include<bits/stdc++.h>
//#define int long long
using namespace std;

int valores[100005];
int freq[100005];
int answer[100005];
int qr[100005];
int ql[100005];

int count;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m; cin>>n>>m;
	int sqrtWidth = floor(sqrt(n));

	freq[0] = -1e6;
	for (int i = 0; i < n; i++) {
		cin>>valores[i];
		valores[i] = valores[i] > 1e5 ? 0 : valores[i];
	}

	set<pair<pair<int, int>, int>> queries;
	for (int i = 0; i < m; i++) {
		int left, right; cin>>left>>right;
		left--; right--;
		qr[i] = right;
		ql[i] = left;
		queries.insert({{left/sqrtWidth, -right}, i});
	}

	int tempAnswer = 0;
	int left = 0;
	int right = -1;	

	for (auto query: queries) {
		int ind = query.second;
		while (right < qr[ind]) {
			right++;
			if (freq[valores[right]] == valores[right]) {
				tempAnswer--;
			}

			freq[valores[right]]++;
			if (freq[valores[right]] == valores[right]) {
				tempAnswer++;
			}
		}

		while (left > ql[ind]) {
			left--;
			if (freq[valores[left]] == valores[left]) {
				tempAnswer--;
			}

			freq[valores[left]]++;
			if (freq[valores[left]] == valores[left]) {
				tempAnswer++;
			}
		}

		while (right > qr[ind]) {
			if (freq[valores[right]] == valores[right]) {
				tempAnswer--;
			}

			freq[valores[right]]--;
			if (freq[valores[right]] == valores[right]) {
				tempAnswer++;
			}

			right--;
		}

		while (left < ql[ind]) {
			if (freq[valores[left]] == valores[left]) {
				tempAnswer--;
			}

			freq[valores[left]]--;
			if (freq[valores[left]] == valores[left]) {
				tempAnswer++;
			}
			left++;
		}

		answer[ind] = tempAnswer;
	}

	for (int i = 0; i < m; i++) {
		cout<<answer[i]<<endl;
	}

	return 0;
}