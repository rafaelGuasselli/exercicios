#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
				if (m >= price[i] && bestFavor(m - price[i], i - 1) + favor[i] > bestFavor(m, i - 1) && (m <= money || (bestSpent(m - price[i], i - 1) + price[i]) > 2000)) {
					dp[m][i] =  bestFavor(m - price[i], i - 1) + favor[i];
					spent[m][i] = bestSpent(m - price[i], i - 1) + price[i];
				} else {
					dp[m][i] = bestFavor(m, i - 1);
					spent[m][i] = bestSpent(m, i - 1);
				}

	cout<<*a.lower_bound(-12031)<<endl;
	cout<<*prev(a.lower_bound(-12031), 1)<<endl;

	return 0;
}