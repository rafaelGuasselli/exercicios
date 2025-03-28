#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCountries, nSports; cin>>nCountries>>nSports;
	vector<pair<pair<int, int>, pair<int, int>>> countries;
	
	for (int i = 0; i < nCountries; i++) {
		countries.push_back({{0,0}, {0, -(i+1)}});
	}

	for (int i = 0; i < nSports; i++) {
		int o, p, b; cin>>o>>p>>b;
		countries[o-1].first.first++;
		countries[p-1].first.second++;
		countries[b-1].second.first++;
	}

	sort(countries.begin(), countries.end(), greater<pair<pair<int, int>, pair<int, int>>>());
	for (int i = 0; i < nCountries; i++) {
		if (i > 0) {
			cout<<" ";
		}

		auto country = countries[i]; 
		cout<<-country.second.second;
	}

	cout<<endl;

	return 0;
}
