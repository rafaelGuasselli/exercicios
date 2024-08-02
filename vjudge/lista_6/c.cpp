#include<bits/stdc++.h>
#define MAX_MONEY 10201
#define MAX_ITEMS 101
using namespace std;

int dp[MAX_MONEY][MAX_ITEMS];
int spent[MAX_MONEY][MAX_ITEMS];

pair<int, int> item[MAX_ITEMS];
int items, money;

int bestFavor(int money, int items){
	if (money <= 0 || items <= 0) {
		return 0;
	}

	return dp[money][items];
}

int bestSpent(int money, int items){
	if (money <= 0 || items <= 0) {
		return 0;
	}

	return spent[money][items];
}

int main(){
	while (cin>>money>>items) {
		for (int i = 1; i <= items; i++) {
			int price, favor; cin>>price>>favor;
			item[i] = make_pair(price, favor);
		}

		sort(item, item+items+1, [](pair<int, int> a, pair<int, int> b) {
			return a.first < b.first;
		});

		for (int m = 1; m <= money+200; m++) {
			for (int i = 1; i <= items; i++) {
				int price = item[i].first;
				int favor = item[i].second;
				
				if (m >= price && bestFavor(m - price, i - 1) + favor > bestFavor(m, i - 1) && (m <= money || (bestSpent(m - price, i - 1) + price) > 2000)) {
					dp[m][i] =  bestFavor(m - price, i - 1) + favor;
					spent[m][i] = bestSpent(m - price, i - 1) + price;
				} else {
					dp[m][i] = bestFavor(m, i - 1);
					spent[m][i] = bestSpent(m, i - 1);
				}
			}
		}

		int biggestFavor = bestFavor(money, items);
		for (int i = money; i <= money+200; i++) {
			if (bestSpent(i, items) > 2000) {
				biggestFavor = max(biggestFavor, bestFavor(i, items));
			}
		}

		
		cout<<biggestFavor<<endl;
	}

	return 0;
}