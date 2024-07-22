#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll totalInversions;
vector<ll> merge(vector<ll> &left, vector<ll> &right){
	ll indexLeft = 0;
	ll indexRight = 0;
	const ll TOTAL_SIZE = left.size() + right.size();
	vector<ll> result(TOTAL_SIZE);

	for (ll i = 0; i < TOTAL_SIZE; i++) {
		bool rightFinished = indexRight == right.size();
		bool stillHasLeft = indexLeft < left.size();
		if (rightFinished || (stillHasLeft && left[indexLeft] <= right[indexRight])) {
			result[i] = left[indexLeft];
			indexLeft++;
			totalInversions += indexRight;
		} else {
			result[i] = right[indexRight];
			indexRight++;
		}
	}


	return result;
}

vector<ll> mergeSort(vector<ll> &array, ll left, ll right){
	if (left > right) {
		return {};
	}

	if (left == right) {
		return {array[left]};
	}

	ll mid = (left+right)/2;
	vector<ll> leftResult = mergeSort(array, left, mid);
	vector<ll> rightResult = mergeSort(array, mid+1, right);
	return merge(leftResult, rightResult);
}

int main() {
	ll n; 
	while (cin>>n) {
		if (n == 0) {
			break;
		}

		vector<ll> array(n);
		for (ll i = 0; i < n; i++) {
			cin>>array[i];
		}

		totalInversions = 0;
		vector<ll> result = mergeSort(array, 0, n-1);
		if (totalInversions % 2 == 1) {
			cout<<"Marcelo"<<endl;
		} else {
			cout<<"Carlos"<<endl;
		}
	}

	return 0;
}