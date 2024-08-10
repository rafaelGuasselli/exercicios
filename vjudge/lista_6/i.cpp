#include<bits/stdc++.h>
#define MAX_N 30
#define ll long long

using namespace std;

int dp[1000000];
int coins[101];
bitset<101> used[1000000];
int amountOfTests;

int main(){
	cin>>amountOfTests;
	for (int i = 0; i < amountOfTests; i++) {
		int price; cin>>price;
		int amountOfCoins; cin>>amountOfCoins;

		int maxValue = 0;
		for (int j = 1; j <= amountOfCoins; j++) {
			cin>>coins[j];
			maxValue += coins[j];
		}

		dp[0] = 0;
		used[0].reset();
		for (int i = 1; i <= maxValue; i++) {
			dp[i] = 200;
			used[i].reset();
		}

		sort(coins, coins+amountOfCoins+1);
		for (int c = 1; c <= amountOfCoins; c++) {
			if (dp[coins[c]] == 1) {
				continue;
			}  

			dp[coins[c]] = 1;
			used[coins[c]].set(c);
		}

		for (int p = 1; p <= maxValue; p++) {
			for (int c = 1; c <= amountOfCoins; c++) {
				if (coins[c] > p) {
					break;
				}

				if (used[p-coins[c]].test(c)) {
					continue;
				}

				if (dp[p] > dp[p-coins[c]] + 1) {
					dp[p] = dp[p-coins[c]] + 1;
					used[p] = used[p-coins[c]];
					used[p].set(c);
				}
			}

			if (p >= price && dp[p] <= amountOfCoins) {
				cout<<p<<" "<<dp[p]<<endl;
				break;
			}
		}
	}

	return 0;
}