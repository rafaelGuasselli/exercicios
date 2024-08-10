#include<bits/stdc++.h>

using namespace std;

int main() {
	int nNumbers, nRanking; cin>>nNumbers>>nRanking;
	vector<int> numbers(nNumbers);
	for (int i = 0; i < nNumbers; i++) {
		cin>>numbers[i];
	}

	sort(numbers.begin(), numbers.end(), greater<int>());
	for (int i = 0; i < nRanking; i++) {
		cout<<numbers[i]<<endl;
	}

	return 0;
}